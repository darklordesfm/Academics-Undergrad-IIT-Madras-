/*
Developer: Balasathya S
Roll Number: EE24B093
Date: 31/08/2024
Input(s): xl, xu, epsilon
Output: Root of the equation through false position
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double fun(double x) {
    return -25+82*x-90*pow(x,2)+44*pow(x,3)-8*pow(x,4)+0.7*pow(x,5);
}

void falseposition(double xl, double xu, double epsilon) {
    double xm, xmold, l, u, f;
    int num_iterations = 0;
    l = fun(xl);
    u = fun(xu);

    if (l*u>=0) {
        printf("False Position method fails.\n");
        return;
    }

    do {
        xmold=xm;
        xm=xu-u*(xl-xu)/(l-u);
        f=fun(xm);
        
        if (f==0.0) {
            break;
        } 
        else if (l*f<0) {
            xu=xm;
            u=f;
        } 
        else {
            xl=xm;
            l=f;
        }num_iterations++;
    } 
    while (fabs((xm-xmold)/xm)*100 > epsilon);

    printf("EE24B093 , %lf , %d\n", xm, num_iterations);
  }

int main(int argc, char *argv[]) {
    falseposition(atof(argv[1]), atof(argv[2]), atof(argv[3]));
}

