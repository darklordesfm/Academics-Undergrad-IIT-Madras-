/**************************************************************************************************************
Developer: Balasathya S
Roll Number: EE24B093
Date: 17/10/2024
Purpose: To understand and find out time taken for a magnet to align to an external magnetic field
Inputs: -> theta_start
        -> theta_stop
        -> alpha
        -> delta_t
Outputs: -> alpha
         -> R^2
         -> switch_time_ns
Assistance/Support used: CHAT GPT AI, And Avi(EE24B091) helped me at some parts.
****************************************************************************************************************/

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define Radius 1                // Define the radius of the sphere
#define Gamma 1.76e11          // Gyromagnetic ratio (rad/(T*s))
#define H 2e-11                 // Constant for magnetic field strength

// Structure to represent polar coordinates
typedef struct {
    double rho;                // Radial distance
    double theta;              // Polar angle
    double phi;                // Azimuthal angle
} PolarCoord;

// Structure to represent Cartesian coordinates
typedef struct {
    double x;                  // x-coordinate
    double y;                  // y-coordinate
    double z;                  // z-coordinate
} CartesianCoord;

// Calculate the change in theta
double theta_difference(double theta, double alpha) {
    return Gamma * alpha * H * sin(theta) / (1 + pow(alpha, 2));
}

// Calculate the change in phi
double phi_difference(double theta, double alpha) {
    return theta_difference(theta, alpha) / (alpha * sin(theta));
}

// Heun's method to compute the time taken to align from theta_start to theta_stop
double heun_time(double theta_start, double theta_stop, double alpha, double delta_t, FILE *trajectory_file) {
    PolarCoord p = {1, theta_start, 0};  // Initialize polar coordinates
    double t = 0;                         // Initialize time

    // Iterate until the polar angle reaches theta_stop
    while (p.theta < theta_stop) {
        // Compute the changes in theta and phi using Heun's method
        double d_theta_1 = theta_difference(p.theta, alpha) * delta_t;
        double d_theta_2 = theta_difference(p.theta + d_theta_1, alpha) * delta_t;
        p.theta += (d_theta_1 + d_theta_2) / 2;  // Update theta

        double d_phi_1 = phi_difference(p.theta, alpha) * delta_t;
        double d_phi_2 = phi_difference(p.theta + d_phi_1, alpha) * delta_t;
        p.phi += (d_phi_1 + d_phi_2) / 2;  // Update phi

        t += delta_t;  // Increment time

        // Write the current trajectory to the file
        fprintf(trajectory_file, "%lf %lf %lf %lf\n", t, Radius * sin(p.theta) * cos(p.phi),
                Radius * sin(p.theta) * sin(p.phi), Radius * cos(p.theta));
    }
    return t;  // Return the total time taken
}

// Calculate the change in x-coordinate
double diff_x(double x, double y, double theta, double alpha) {
    double m = sqrt(pow(x, 2) + pow(y, 2));  // Calculate the magnitude
    double sin_phi = y / m;                   // Calculate sin(phi)
    double cos_phi = x / m;                   // Calculate cos(phi)
    return Radius * (cos_phi * cos(theta) * theta_difference(theta, alpha) -
                     sin_phi * sin(theta) * phi_difference(theta, alpha));
}

// Calculate the change in y-coordinate
double diff_y(double x, double y, double theta, double alpha) {
    double m = sqrt(pow(x, 2) + pow(y, 2));  // Calculate the magnitude
    double sin_phi = y / m;                   // Calculate sin(phi)
    double cos_phi = x / m;                   // Calculate cos(phi)
    return Radius * (sin_phi * cos(theta) * theta_difference(theta, alpha) +
                     cos_phi * sin(theta) * phi_difference(theta, alpha));
}

// Calculate the change in z-coordinate
double diff_z(double theta, double alpha) {
    return -Radius * sin(theta) * theta_difference(theta, alpha); // Change in z based on theta
}

// Normalize a Cartesian coordinate to have a magnitude equal to the radius
void normalize_cartesian(CartesianCoord *c) {
    double magnitude = sqrt(pow(c->x, 2) + pow(c->y, 2) + pow(c->z, 2)); // Calculate magnitude
    c->x *= Radius / magnitude;  // Scale x
    c->y *= Radius / magnitude;  // Scale y
    c->z *= Radius / magnitude;  // Scale z
}

// Find theta from Cartesian coordinates
double find_theta(double x, double y, double z) {
    double val = atan2(sqrt(pow(x, 2) + pow(y, 2)), z); // Calculate theta using atan2
    if (val < 0) val += M_PI;  // Adjust to ensure theta is non-negative
    return val;
}

// Calculate the time taken to align using Cartesian coordinates
double cartesian_time(double theta_start, double theta_stop, double alpha, double delta_t, FILE *trajectory_file) {
    double t = 0;  // Initialize time
    CartesianCoord c = {Radius * sin(theta_start), 0, Radius * cos(theta_start)}; // Initialize Cartesian coordinates

    // Iterate until the calculated theta reaches theta_stop
    while (find_theta(c.x, c.y, c.z) < theta_stop) {
        double theta = find_theta(c.x, c.y, c.z);  // Current theta
        double x = c.x, y = c.y, z = c.z;          // Current coordinates
        // Update Cartesian coordinates using differential equations
        c.x += diff_x(x, y, theta, alpha) * delta_t;
        c.y += diff_y(x, y, theta, alpha) * delta_t;
        c.z += diff_z(theta, alpha) * delta_t;
        normalize_cartesian(&c);  // Normalize to maintain radius

        t += delta_t;  // Increment time

        // Write the current trajectory to the file
        fprintf(trajectory_file, "%lf %lf %lf %lf\n", t, c.x, c.y, c.z);
    }
    return t;  // Return the total time taken
}

// Calculate the RMS error between polar and Cartesian trajectories
double calculate_rms_error(char *polar_file, char *cartesian_file) {
    FILE *polar = fopen(polar_file, "r");       // Open polar trajectory file
    FILE *cartesian = fopen(cartesian_file, "r"); // Open Cartesian trajectory file

    // Check for successful file opening
    if (!polar || !cartesian) {
        fprintf(stderr, "Error opening trajectory files\n");
        exit(1);
    }

    double sum_squared_diff = 0;  // Initialize sum of squared differences
    int count = 0;                // Initialize count of data points
    double t1, x1, y1, z1, t2, x2, y2, z2;

    // Read data from both files and compute the squared differences
    while (fscanf(polar, "%lf %lf %lf %lf", &t1, &x1, &y1, &z1) == 4 &&
           fscanf(cartesian, "%lf %lf %lf %lf", &t2, &x2, &y2, &z2) == 4) {
        double diff_x = x1 - x2;  // Difference in x-coordinates
        double diff_y = y1 - y2;  // Difference in y-coordinates
        double diff_z = z1 - z2;  // Difference in z-coordinates
        sum_squared_diff += pow(diff_x, 2) + pow(diff_y, 2) + pow(diff_z, 2); // Accumulate squared differences
        count++;  // Increment count
    }

    fclose(polar);    // Close polar trajectory file
    fclose(cartesian); // Close Cartesian trajectory file

    return sqrt(sum_squared_diff / count);  // Return the RMS error
}

int main(int argc, char *argv[]) {
    // Check for correct number of command-line arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <theta_start> <theta_stop> <alpha> <delta_t>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert command-line arguments to appropriate values
    double theta_start = atof(argv[1]) * M_PI / 180;  // Convert degrees to radians
    double theta_stop = atof(argv[2]) * M_PI / 180;   // Convert degrees to radians
    double alpha = atof(argv[3]);                       // Coefficient
    double delta_t = atof(argv[4]);                     // Time step

    // Open files for trajectory output
    FILE *polar_file = fopen("polar_trajectory.txt", "w");
    FILE *cartesian_file = fopen("cartesian_trajectory.txt", "w");

    // Check for successful file opening
    if (!polar_file || !cartesian_file) {
        fprintf(stderr, "Error opening output files\n");
        return EXIT_FAILURE;
    }

    // Compute the times using both methods and write to files
    double heun_t = heun_time(theta_start, theta_stop, alpha, delta_t, polar_file);
    double cartesian_t = cartesian_time(theta_start, theta_stop, alpha, delta_t, cartesian_file);

    fclose(polar_file);    // Close polar trajectory file
    fclose(cartesian_file); // Close Cartesian trajectory file

    // Calculate the RMS error between the two trajectories
    double rms_error = calculate_rms_error("polar_trajectory.txt", "cartesian_trajectory.txt");

    // Output the results
    printf("%.6f %.6f %.6f\n", alpha, rms_error, heun_t);  // Output the RMS error

    return EXIT_SUCCESS;  // Successful program termination
}
