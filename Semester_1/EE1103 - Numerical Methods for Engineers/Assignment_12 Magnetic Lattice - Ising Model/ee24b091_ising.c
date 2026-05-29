// Developer: Balasathya (EE24B093), Avi Shah (EE24B091)
// Date: 25 October 2024
// Purpose: To observe magnetic spins align to form ferromagnetic or antiferromagnetic configuration based on constant coupling and normalized temperature
// spontaneously, ie change to an energy minima
// Inputs: N (lattice size), J (constant coupling between nearest neighbours), T (normalized temperature)
// Outputs: maxiter, totdelE, total_M
// Used ChatGPT AI to understand underlying concept and write a part of the code

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITER 5e3
#define TOLERANCE 1e-6

// struct to hold old and new spins with other info
typedef struct {
    int N;              // Lattice size
    double J;           // Coupling constant
    double T;           // Temperature
    int** spins;        // Current configuration
    int** new_spins;    // New configuration
    double totalE;      // Total energy
    double totalM;      // Total magnetization
} IsingLattice;

// Function declarations
IsingLattice* initializeLattice(int N, double J, double T);
void freeLattice(IsingLattice* lattice);
double calculateLocalEnergy(IsingLattice* lattice, int i, int j);
double calculateTotalEnergy(IsingLattice* lattice);
double calculateMagnetization(IsingLattice* lattice);
int metropolisStep(IsingLattice* lattice, int* totiterations, double* totaldelE);

// initialise lattice with random 1's and -1's
IsingLattice* initializeLattice(int N, double J, double T) {
    IsingLattice* lattice = (IsingLattice*)malloc(sizeof(IsingLattice));
    lattice->N = N;
    lattice->J = J;
    lattice->T = T;

    lattice->spins = (int**)malloc(N * sizeof(int*));
    lattice->new_spins = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        lattice->spins[i] = (int*)malloc(N * sizeof(int));
        lattice->new_spins[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            lattice->spins[i][j] = (rand() % 2) ? 1 : -1;
            lattice->new_spins[i][j] = lattice->spins[i][j];
        }
    }

    lattice->totalE = calculateTotalEnergy(lattice);
    lattice->totalM = calculateMagnetization(lattice);
    return lattice;
}

// free all memory of lattice
void freeLattice(IsingLattice* lattice) {
    for (int i = 0; i < lattice->N; i++) {
        free(lattice->spins[i]);
        free(lattice->new_spins[i]);
    }
    free(lattice->spins);
    free(lattice->new_spins);
    free(lattice);
}

// calculate energy around a single lattice point
double calculateLocalEnergy(IsingLattice* lattice, int i, int j) {
    int N = lattice->N;
    int up = (i - 1 + N) % N;  // avoid negative mod
    int down = (i + 1) % N;
    int left = (j - 1 + N) % N;
    int right = (j + 1) % N;

    return -lattice->J * lattice->spins[i][j] * (
        lattice->spins[up][j] + lattice->spins[down][j] +
        lattice->spins[i][left] + lattice->spins[i][right]
    );
}

// calculate energy of full lattice
double calculateTotalEnergy(IsingLattice* lattice) {
    double totalEnergy = 0;
    for (int i = 0; i < lattice->N; i++) {
        for (int j = 0; j < lattice->N; j++) {
            totalEnergy += calculateLocalEnergy(lattice, i, j);
        }
    }
    return totalEnergy / 2.0;  // Avoid double counting
}

// calculate magnetisation of lattice
double calculateMagnetization(IsingLattice* lattice) {
    double M = 0;
    for (int i = 0; i < lattice->N; i++) {
        for (int j = 0; j < lattice->N; j++) {
            M += lattice->spins[i][j];
        }
    }
    return fabs(M) / (lattice->N * lattice->N);
}

// run the metropolis step while there is significant change in energy
int metropolisStep(IsingLattice* lattice, int* totiterations, double* totaldelE) {
    double oldE, newE, deltaE;
    double oldTotalE = lattice->totalE;
    (*totiterations) = 0;

    do {
        oldTotalE = lattice->totalE;
        (*totiterations)++;

        for (int i = 0; i < lattice->N; i++) {
            for (int j = 0; j < lattice->N; j++) {
                oldE = calculateLocalEnergy(lattice, i, j);
                lattice->new_spins[i][j] = -lattice->spins[i][j];
                newE = -oldE;
                deltaE = newE - oldE;

                if (deltaE <= 0 || (double)rand() / RAND_MAX < exp(-deltaE / lattice->T)) {
                    lattice->spins[i][j] = lattice->new_spins[i][j];
                } else {
                    lattice->new_spins[i][j] = lattice->spins[i][j];
                }
            }
        }

        lattice->totalE = calculateTotalEnergy(lattice);
        lattice->totalM = calculateMagnetization(lattice);
        *totaldelE = fabs(lattice->totalE - oldTotalE);

    } while (*totaldelE >= TOLERANCE && *totiterations < MAX_ITER);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        return 1;
    }

    srand(time(NULL));
    int N = atoi(argv[1]);
    double J = atof(argv[2]);
    double T = atof(argv[3]);

    int totiterations;
    double totaldelE;

    IsingLattice* lattice = initializeLattice(N, J, T);
    metropolisStep(lattice, &totiterations, &totaldelE);

    printf("%d , %f , %f\n", totiterations, totaldelE, lattice->totalM);

    freeLattice(lattice);
    return 0;
}
