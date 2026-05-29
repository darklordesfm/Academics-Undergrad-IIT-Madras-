/*
Developer: Balasathya Saravanan
Roll Number: EE24B093
Date: 06/09/2024
Input(s): None
Output(s): Theta (in degrees, between 0 and 180) for which the error is maximum
Help Used: Used ChatGPT for syntax
*/

#include <stdio.h>
#include <math.h>
#define pi 3.14159265358979323846                 //we need 'pi' value for converting degrees into radians
#define DEG_TO_RAD(deg) ((deg)*(pi)/180.0)

//Defining Bhaskara's method of sin(theta)
double sine_approx(double theta) {
    double a=theta*(180-theta);
    double b=0.25*(40500-a);
    return a/b;
}

//Main function
int main() {
  double max_error=0.0;
  double max_theta=0.0;
  for (double theta = 0.0; theta <= 180; theta += 0.00001) {       //iterating theta from 0 degrees to 180 degrees with 0.00001 degree increment)
    double approx_value = sine_approx(theta);           //Approximate value by Bhaskara
    double actual_value = sin(DEG_TO_RAD(theta));       //Actual value by math library
    double error=fabs(approx_value-actual_value);     //Error (Absolute value)
    if (error>max_error) {
      max_error=error;
      max_theta=theta;
    }
  }
  printf("EE24B093,%.5f,%.12f\n", max_theta, max_error);
  return 0;
}
  
    
    


