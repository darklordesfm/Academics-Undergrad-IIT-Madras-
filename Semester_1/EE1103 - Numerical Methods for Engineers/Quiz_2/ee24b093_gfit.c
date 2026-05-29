/********************************************************
Developer: Balasathya S
Roll Number: EE24B093
Date: 23-10-2024
Input(s): N and sigma
Output(s): aL , bL , aG , bG , R^2
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Box-Muller Transform to generate Gaussian noise
double box_muller(double mean, double stddev) {
    static int generate;
    static double z1;
    double u1, u2, z0;

    if (!generate) {
        u1 = rand() / (double)RAND_MAX;
        u2 = rand() / (double)RAND_MAX;
        z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        z1 = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);
        generate = 1;
        return z0 * stddev + mean;
    } else {
        generate = 0;
        return z1 * stddev + mean;
    }
}

// Lorentzian function
double lorentzian(double x, double aL, double bL) {
    return aL / (1.0 + bL * x * x);
}

// Gaussian function
double gaussian(double x, double aG, double bG) {
    return aG * exp(-bG * x * x);
}

// Function to calculate R-squared
double calculate_r_squared(double* y_actual, double* y_pred, int N) {
    double ss_res = 0.0, ss_tot = 0.0, mean_y = 0.0;

    for (int i = 0; i < N; i++) {
        mean_y += y_actual[i];
    }
    mean_y /= N;

    for (int i = 0; i < N; i++) {
        ss_res += pow(y_actual[i] - y_pred[i], 2);
        ss_tot += pow(y_actual[i] - mean_y, 2);
    }

    return 1 - (ss_res / ss_tot);
}

// Write data to file for plotting or fitting
void write_data_to_file(const char *filename, double* x, double* y, int N) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < N; i++) {
        fprintf(file, "%f %f\n", x[i], y[i]);
    }
    fclose(file);
}

// Linear regression function for log(R^2) vs sigma
void linear_regression(double* x, double* y, int N, double* slope, double* intercept) {
    double sum_x = 0.0, sum_y = 0.0, sum_xx = 0.0, sum_xy = 0.0;

    for (int i = 0; i < N; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xx += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }

    double denom = N * sum_xx - sum_x * sum_x;
    if (denom != 0) {
        *slope = (N * sum_xy - sum_x * sum_y) / denom;
        *intercept = (sum_y * sum_xx - sum_x * sum_xy) / denom;
    } else {
        *slope = 0;
        *intercept = 0;
    }
}

int main() {
    int N = 20;  // Number of data points
    double sigma_values[] = {0.1, 0.2, 0.5, 1.0, 1.5, 2.0};  // Different sigma values
    int num_sigmas = sizeof(sigma_values) / sizeof(sigma_values[0]);

    double *x = (double *)malloc(N * sizeof(double));
    double *y = (double *)malloc(N * sizeof(double));
    double *y_noisy = (double *)malloc(N * sizeof(double));

    double aL = 1.0;  // Lorentzian parameter aL
    double bL = 0.1;  // Lorentzian parameter bL
    double aG, bG, R2;  // Fitted Gaussian parameters and R^2

    // Arrays to store sigma and log(R^2) values
    double *sigma = (double *)malloc(num_sigmas * sizeof(double));
    double *log_R2 = (double *)malloc(num_sigmas * sizeof(double));

    for (int s = 0; s < num_sigmas; s++) {
        double sigma_val = sigma_values[s];

        // Generate Lorentzian with Gaussian noise
        for (int i = 0; i < N; i++) {
            x[i] = -3 + i * 6.0 / (N - 1);  // Spread x over the range [-3, 3]
            y[i] = lorentzian(x[i], aL, bL);
            y_noisy[i] = y[i] + box_muller(0, sigma_val);  // Add Gaussian noise
        }

        // Write noisy data to a file for fitting or plotting
        write_data_to_file("lorentzian_data.txt", x, y_noisy, N);

        // Fit Gaussian to noisy data using Gnuplot
        system("E:\\Personal\\gnuplot\\bin\\gnuplot.exe -e \""
               "f(x) = aG * exp(-bG * x**2);"
               "fit f(x) 'lorentzian_data.txt' using 1:2 via aG, bG;"
               "set print 'fit_results.txt';"
               "print aG, bG;"
               "quit\"");

        // Read aG and bG from Gnuplot fit file
        FILE *fit_file = fopen("fit_results.txt", "r");
        if (fit_file == NULL) {
            printf("Error: fit_results.txt not found. Fit the data with Gnuplot first.\n");
            return 1;
        }
        fscanf(fit_file, "%lf %lf", &aG, &bG);
        fclose(fit_file);

        // Compute the fitted Gaussian curve
        double *y_fitted = (double *)malloc(N * sizeof(double));
        for (int i = 0; i < N; i++) {
            y_fitted[i] = gaussian(x[i], aG, bG);
        }

        // Calculate R-squared
        R2 = calculate_r_squared(y_noisy, y_fitted, N);

        // Store sigma and log(R^2) for power-law fitting
        sigma[s] = sigma_val;
        log_R2[s] = log(R2);

        // Free allocated memory for y_fitted
        free(y_fitted);
    }

    // Perform linear regression to find the power-law exponent
    double slope, intercept;
    linear_regression(sigma, log_R2, num_sigmas, &slope, &intercept);

    printf("The power-law dependence of log(R^2) vs sigma is: %.4f * sigma + %.4f\n", slope, intercept);

    // Free allocated memory
    free(x);
    free(y);
    free(y_noisy);
    free(sigma);
    free(log_R2);

    return 0;
}
