/*
Developer: Balasathya
Roll No: EE24B093
Date: 23/08/2024
Input(s): 1. The number of random values to generate (N)
          2. The mean
          3. The standard deviation
Output(s): Counts of values within 1, 2, and 3 standard deviations           
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void distribution(int N, double mean, double stdev) {
    int count1 = 0, count2 = 0, count3 = 0;
    double normal_value;

    for (int i = 0; i < N; i += 1) {
        // RAND function to generate two uniform random numbers between -1 and 1
        double u1 = (double)rand() / RAND_MAX * 2 - 1; // Uniform between -1 and 1
        double u2 = (double)rand() / RAND_MAX * 2 - 1; // Uniform between -1 and 1

        // Box-Muller transformation
        // Z0=sqrt(-2lnU1)cos(2piU2)
        // Z1=sqrt(-2lnU1)sin(2piU2)
        double z0 = sqrt(-2.0 * log(fabs(u1))) * cos(2.0 * M_PI * u2);
        double z1 = sqrt(-2.0 * log(fabs(u1))) * sin(2.0 * M_PI * u2);

        // Transform to normal distribution with given mean and stdev
        normal_value = mean + z0 * stdev;

        // Count how many values fall within 1, 2 and 3 standard deviations
        if (normal_value >= mean - stdev && normal_value <= mean + stdev) {
            count1++;
        }
        if (normal_value >= mean - 2 * stdev && normal_value <= mean + 2 * stdev) {
            count2++;
        }
        if (normal_value >= mean - 3 * stdev && normal_value <= mean + 3 * stdev) {
            count3++;
        }
    }

    printf("%d,%d,%d\n", count1, count2, count3);
    
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <N> <mean> <stdev>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0 || N > 10000) {
        printf("N must be a positive integer less than or equal to 10000.\n");
        return 1;
    }
    
    double mean = atof(argv[2]);
    double stdev = atof(argv[3]);

    // Seed the random number generator
    srand(time(NULL));

    distribution(N, mean, stdev);

    return 0;
}

