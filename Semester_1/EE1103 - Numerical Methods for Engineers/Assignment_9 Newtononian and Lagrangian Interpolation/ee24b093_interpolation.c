/*
Developer: EE24B093 (Balasathya S)
Date: 04/10/2024
Input(s): polynomial_order (order) , xstart , xend , x0
Output(s): f(x0)(Actual value of function) , newton(x0) (Value by newton's interpolation) , lagrange(x0) (Value by lagrange's interpolation)
Purpose(s): This program uses the Lagrange and Newton interpolation methods to fit a curve onto a given set of points, then caluclate the
            value of this curve at a required x. This program samples points which are equidistant from each other (the algorithm will still
            work if the points are not equidistant).
Observation(s): Newton and Lagrange interpolation will give the same values if the data points are equally spaced. Here since the
                data points are equidistant the outputs of newton and lagrange comes same.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);                                                                 //Function to evaluate (Runge's function)
double lagrange(double* X, double* Y, int order, double xreq);                      //Lagrange interpolation function
double newton_interpolation(double* X, double* Y, int order, double xreq);          //Newton interpolation function

int main(int argc, char* argv[]) {
    if (argc != 5) {
        printf("Usage: %s <polynomial_order> <xstart> <xend> <xreq>\n", argv[0]);           // Check for the correct number of command-line arguments
        return 1;                                                                   // Exit if arguments are invalid
    }

    int order = atoi(argv[1]);                                                      // Passing command-line arguments
    double xstart = atof(argv[2]);
    double xend = atof(argv[3]);
    double xreq = atof(argv[4]);
    if (xstart >= xend || order < 0) {                                              // Validate inputs: xstart must be less than xend and order must be non-negative
        printf("Invalid input: xstart must be less than xend, and order must be non-negative.\n");
        return 1;                                                                   // Exit if inputs are invalid
    }

    double* X = malloc((order + 1) * sizeof(double));                               // Allocate memory for array X
    double* Y = malloc((order + 1) * sizeof(double));                               // Allocate memory for array Y

    for (int i = 0; i < order + 1; i++) {                                           // Generate equidistant points in the interval [xstart, xend]
        X[i] = xstart + ((double)i / order) * (xend - xstart);
        Y[i] = f(X[i]);                                                             // Calculate corresponding y value using the function f
    }
    printf("%lf , %lf , %lf\n", f(xreq) , newton_interpolation(X, Y, order, xreq) , lagrange(X, Y, order, xreq));
                                                                                    // Print exact function value, Newton interpolation result, and Lagrange interpolation result
    free(X);                                                                        // Free allocated memory for array X
    free(Y);                                                                        // Free allocated memory for array Y
    return 0;                                                                       // Exit the program successfully
}

double f(double x) {                                                                // Function to compute f(x) as given in the problem statement (Runge's function)
    return 1.0 / (1.0 + 25.0 * pow(x, 2));                                          // Evaluates the function
}

double lagrange(double* X, double* Y, int order, double xreq) {                     // Function to perform Lagrange interpolation
    double ans = 0;                                                                 // Initialize result
    for (int i = 0; i < order + 1; i++) {                                           // Loop through each point for interpolation
        double term = Y[i];                                                         // Start with the corresponding Y value
        for (int j = 0; j < order + 1; j++) {                                       // Compute the product for Lagrange's basis polynomial
            if (i != j) {                                                           // Ensure not to include the same index
                term = term * (xreq - X[j]) / (X[i] - X[j]);                        // Calculate the term
            }
        }
        ans += term;                                                                // Add the term to the result
    }
    return ans;                                                                     // Return the final result
}

double newton_interpolation(double* X, double* Y, int order, double xreq) {         // Function to perform Newton interpolation
    double** divided_differences = malloc((order + 1) * sizeof(double*));           // Allocate memory for divided differences tabl
    for (int i = 0; i <= order; i++) {
        divided_differences[i] = malloc((order + 1) * sizeof(double));              // Allocate each row
        divided_differences[i][0] = Y[i];                                           // Initialize first column with Y values
    }
    for (int k = 1; k <= order; k++) {                                              // Fill the divided differences table
        for (int i = 0; i <= order - k; i++) {                                      // Compute the divided difference
            divided_differences[i][k] = (divided_differences[i + 1][k - 1] - divided_differences[i][k - 1]) / (X[i + k] - X[i]);
        }
    }
    double term = 1;                                                                // Initialize term for Newton's polynomial
    double yint = divided_differences[0][0];                                        // Start with the first term
    for (int k = 1; k <= order; k++) {                                              // Calculate the interpolated value
        term *= (xreq - X[k - 1]);                                                  // Update the term
        yint += divided_differences[0][k] * term;                                   // Add the current term to yint
    }
    for (int i = 0; i <= order; i++) {
        free(divided_differences[i]);                                               // Free allocated memory for the divided differences table
    }
    free(divided_differences);
    return yint;                                                                    // Return the final interpolated value
}
