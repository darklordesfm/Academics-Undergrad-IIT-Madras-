/*************************************************************************************************
Developer: Balasathya S
Roll Number: EE24B093
Date: 17/10/2024
Description: This program calculates the roots of a given set of linear equations using the
             gaussian elimination method.
Input: Takes 2 command line arguments
            -> File with 2D arrays of numbers (N rows and N+1 columns).
            -> Number of unknowns (N)
Output: Prints all N unknowns seperated by a space (\t).
Support Used: Used CHAT GPT AI for syntax and a part of the code.
*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DYNAMIC_TOLERANCE 1e-9         // Tolerance for checking small values
                                       /* TOL is dynamically adjusted based on the magnitude of the
                                       diagonal element in Eliminate(). This prevents issues with
                                       very small values in the matrix. */

void Pivot(double **a, double *b, double *s, int N, int k);
/* The Pivot function handles partial pivoting to improve numerical stability
   by swapping rows with the largest leading coefficient in each column. */
void Eliminate(double **a, double *b, int N, int *er);
/* The Eliminate function performs Gaussian elimination to transform the
   system into an upper triangular form. */
void Substitute(double **a, double *b, double *x, int N);
/* The Substitute function performs back substitution to find the values
   of the unknowns. */

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <N>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int N = atoi(argv[2]);

    // Check if N is valid (N > 0)
    if (N <= 0) {
        printf("Error: N must be a positive integer greater than 0.\n");
        return 1;
    }

    FILE *file = fopen(filename, "r");    //Opening the file
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);  //error statement if file does not open
        return 1;
    }

    // Allocate memory for the augmented matrix a and the result vector b
    double **a = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        a[i] = (double *)malloc((N + 1) * sizeof(double));
    }
    double *b = (double *)malloc(N * sizeof(double));
    double *x = (double *)malloc(N * sizeof(double));
    double *s = (double *)malloc(N * sizeof(double)); // Scaling vector

    // Read the matrix and vector from file
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) { // Expecting N + 1 columns
            if (fscanf(file, "%lf", &a[i][j]) != 1) {
                printf("Error: Invalid input in file %s, expected a numeric value.\n", filename);
                fclose(file);
                return 1;
            }
        }
        b[i] = a[i][N]; // The last column is the b vector
    }
    fclose(file);

    // Normalize rows to improve numerical stability
    for (int i = 0; i < N; i++) {
        double maxValue = 0.0;
        for (int j = 0; j < N; j++) {
            if (fabs(a[i][j]) > maxValue) {
                maxValue = fabs(a[i][j]);
            }
        }
        if (maxValue == 0) {
            printf("Error: Zero row detected, no unique solution.\n");
            return 1;
        }
        for (int j = 0; j < N; j++) {
            a[i][j] /= maxValue;   // Normalize row
        }
        b[i] /= maxValue;
    }

    int er = 0;        // Error flag

    Eliminate(a, b, N, &er);              //Perform Gaussian Elimnation

    if (er == 0) {
        Substitute(a, b, x, N);           // If no error, perform back substitution
        for (int i = 0; i < N; i++) {
            printf("%lf\t", x[i]);
        }
    } else {
        printf("Singular matrix detected. No unique solution.\n");
    }
    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(a[i]);
    }
    free(a);
    free(b);
    free(x);
    free(s);

    return 0;
}

// Pivot function (partial pivoting)
void Pivot(double **a, double *b, double *s, int N, int k) {
    int p = k;
    double big = fabs(a[k][k] / s[k]);
    for (int i = k + 1; i < N; i++) {
        double temp = fabs(a[i][k] / s[i]);
        if (temp > big) {
            big = temp;
            p = i;
        }
    }
    if (p != k) {
        for (int j = 0; j < N; j++) {        // Swap rows in matrix a
            double temp = a[p][j];
            a[p][j] = a[k][j];
            a[k][j] = temp;
        }
        double temp = b[p];        // Swap values in vector b
        b[p] = b[k];
        b[k] = temp;

        temp = s[p];              // Swap scaling factors
        s[p] = s[k];
        s[k] = temp;
    }
}

// Gaussian elimination with partial pivoting
void Eliminate(double **a, double *b, int N, int *er) {
    double *s = (double *)malloc(N * sizeof(double));

    for (int i = 0; i < N; i++) {
        s[i] = fabs(a[i][0]);
        for (int j = 1; j < N; j++) {
            if (fabs(a[i][j]) > s[i]) {
                s[i] = fabs(a[i][j]);      // Initialize scaling factors
            }
        }
    }
    for (int k = 0; k < N - 1; k++) {
        Pivot(a, b, s, N, k);               // Pivot

        // Dynamically adjust tolerance based on the matrix value
        double TOL = DYNAMIC_TOLERANCE * fabs(a[k][k]);
        if (fabs(a[k][k] / s[k]) < TOL)  {   // Check for singular matrix
            *er = -1;
            free(s);
            return;
        }

        for (int i = k + 1; i < N; i++) {         // Eliminate
            double factor = a[i][k] / a[k][k];
            for (int j = k; j < N; j++) {
                a[i][j] -= factor * a[k][j];
            }
            b[i] -= factor * b[k];
        }
    }
    double TOL = DYNAMIC_TOLERANCE * fabs(a[N - 1][N - 1]);
    if (fabs(a[N - 1][N - 1]) < TOL) {
        *er = -1;
    }
    free(s);
}

// Back substitution
void Substitute(double **a, double *b, double *x, int N) {
    for (int i = N - 1; i >= 0; i--) {
        double sum = b[i];
        for (int j = i + 1; j < N; j++) {
            sum -= a[i][j] * x[j];
        }
        x[i] = sum / a[i][i];
    }
}
