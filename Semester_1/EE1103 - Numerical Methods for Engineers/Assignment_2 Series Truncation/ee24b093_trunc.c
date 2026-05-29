/*
Developer: Balasathya
Roll No: EE24B093
Date: 23/08/2024
Input: 1. int for the number to terms in the truncated series for sin(x) 
       2. float for the value of x
Output: 1. The estimated value of sin(x) using the truncated series
        2. The error between the estimated value and the true value
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to calculate factorial of an integer

int fact(int n) {
    if (n==0 | n==1) return 1;
    else return n*fact(n-1);
}

// Function to calculate sinx series

double sin_series(float x, int n) {
    float sin_x = 0;
    for (int i = 0; i < n; i++) {
        double term = pow(x, 2 * i + 1) / fact(2 * i + 1); 
        // Calculating the general term in sinx expansion
        if (i % 2 == 1) {
            term = -term;
        }
        sin_x += term;
    }
    return sin_x; // Return the estimated sin(x)
}

int main(int argc, char *argv[]) {
    float sin_x = sin_series(atoi(argv[1]), atof(argv[2]));
    // Output the results formatted to three decimal places
    printf("%.3f %.3f",  sin_x, fabs(sin(x) - sin_x)); // fabs is used to compute the absolute value of a floating-point
}

