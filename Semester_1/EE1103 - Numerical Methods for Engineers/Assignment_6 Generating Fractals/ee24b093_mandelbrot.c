/*
Developer: Balasathya S
Roll Number: EE24B093
Date: 18-09-2024
Input(s): xmin , xmax , ymin , ymax, maxiter, xres , out.jpg
Output: Generates a mandelbrot set

The Mandelbrot set is a set of complex numbers defined by a particular iterative sequence. Starting with z0 = 0
and iterating the relation: z(n+1)^2 = zn^2 + c , Where c is a complex number, and zn is a sequence of complex numbers.
If the sequence does not tend toward infinity (i.e., if the absolute value of zn remains bounded), then c is 
considered to be part of the Mandelbrot set. If the value grows beyond a certain limit (usually |zn| > 2) then 
c is not part of the set. The function mandelbrot(Complex c, int max_iter) determines whether a given complex number c 
is in the Mandelbrot set by iterating the relation and checking if |zn| exceeds 2 within a maximum number of iterations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {                             //defining complex numbers and operations
    double real;
    double imag;
} Complex;

Complex complex_add(Complex a, Complex b) {  //addition
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex complex_mul(Complex a, Complex b) {  //multiplication
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

double complex_abs(Complex c) {             //absolute value
    return sqrt(c.real * c.real + c.imag * c.imag);
}

int mandelbrot(Complex c, int max_iter) {   //iterating Z(n+1) = Z(n)^2 + c
    Complex z = {0.0, 0.0};
    int n;
    for (n = 0; n < max_iter; n++) {
        if (complex_abs(z) > 2.0) {
            return n;                       //not in the Mandelbrot set
        }
        z = complex_add(complex_mul(z, z), c);
    }
    return max_iter;                        //in the Mandelbrot set
}

void generate_mandelbrot_image(double xmin, double xmax, double ymin, double ymax, int max_iter, int xres, const char *filename) {
    // Calculate yres based on aspect ratio
    int yres = (int)(xres * (ymax - ymin) / (xmax - xmin));
    
    // Create an image buffer
    unsigned char *image = (unsigned char *)malloc(xres * yres * 3);    
    /* For each pixel, there are 3 color channels:
	 Red (R)
	 Green (G)
	 Blue (B)
     Each of these channels uses 1 byte of memory (8 bits), meaning a total of 3 bytes per pixel. */

    /* RGB is a common color model used for digital images. Each of the red, green, and blue channels 
       can take values from 0 to 255, allowing for 256 shades of each color. The combination of these 
       three channels creates millions of color possibilities for the image. In grayscale images, all 
       three channels (R, G, and B) would have the same value, but we still need to allocate space 
       for all three channels for each pixel. */

    if (image == NULL) {
        fprintf(stderr, "Failed to allocate memory for image.\n");
        exit(EXIT_FAILURE);
    }

    // Define the scaling factors
    double x_scale = (xmax - xmin) / (xres - 1);
    double y_scale = (ymax - ymin) / (yres - 1);

    for (int y = 0; y < yres; y++) {
        for (int x = 0; x < xres; x++) {
            Complex c;
            c.real = xmin + x * x_scale;
            c.imag = ymin + y * y_scale;

            int iter = mandelbrot(c, max_iter);
            int color = 255 * (iter / max_iter);  //simple grayscale coloring
            image[(y * xres + x) * 3 + 0] = color;  //red
            image[(y * xres + x) * 3 + 1] = color;  //green
            image[(y * xres + x) * 3 + 2] = color;  //blue
        }
    }

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", xres, yres);
    fprintf(file, "255\n");
    fwrite(image, 1, xres * yres * 3, file);

    fclose(file);
    free(image);
}

int main(int argc, char *argv[]) {
    if (argc != 8) {
        fprintf(stderr, "Usage: %s <xmin> <xmax> <ymin> <ymax> <maxiter> <xres> <out.ppm>\n", argv[0]); 
        return EXIT_FAILURE;
    }

    double xmin = atof(argv[1]);
    double xmax = atof(argv[2]);
    double ymin = atof(argv[3]);
    double ymax = atof(argv[4]);
    int max_iter = atoi(argv[5]);
    int xres = atoi(argv[6]);
    const char *output_file = argv[7];

    generate_mandelbrot_image(xmin, xmax, ymin, ymax, max_iter, xres, output_file);

    return EXIT_SUCCESS;
}
