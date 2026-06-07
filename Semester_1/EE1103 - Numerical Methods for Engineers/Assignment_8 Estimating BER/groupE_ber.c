/*
Developer(s) : EE24B066 , EE24B093 , EE24B053
Date         : 29 September 2024
Purpose      : Estimate BER and Visibility from photon detection timestamps
Input(s)     : 1 string (name of datafile)
Output(s)    : group, BER1, Visibility1, BER2, Visibility2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int window_3ns(int *time, int count);
void without_g(int *time, int count, int start_pos, double *BER1, double *V1);
void with_g(int *time, int count, int start_pos, double *BER2, double *V2);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Only one input allowed\n");                                         //check for number of inputs
        return 1;
    }
    
    FILE *fptr = fopen(argv[1], "r");
    if (!fptr) {
        printf("Error opening file\n");                                             //checking for number of inputs
        return 1;
    }
    
    int *time = (int*)malloc(3000 * sizeof(int));                                   //allocating memory to array
    if (!time) {
        perror("Memory allocation failed");                                         //checking if memory was allocated safely
        fclose(fptr);
        return EXIT_FAILURE;
    }
    char buffer[1024];                                                              //creating buffer to read csv file
    int count = 0;

    while (fgets(buffer, sizeof(buffer), fptr)) {                                   //reading csv file for data
        char *data_points = strtok(buffer, ",");
        if (data_points) {
            time[count++] = atoi(data_points) % 32000;                              // Storing timestamp modulo 32000
        }
    }
    
    fclose(fptr);                                                                   //closing the csv file after reading data

    if (count == 0) {
        printf("No data found\n");                                                  //if incorrect file was opened
        free(time);
        return 1;
    }
    
    int start_pos = window_3ns(time, count);                                        //finding starting position of 3ns window
    double BER1, BER2, V1, V2;

    without_g(time, count, start_pos, &BER1, &V1);                                  //calling function to find BER1 , V1
    with_g(time, count, start_pos, &BER2, &V2);                                     //calling function to find BER2 , V2

    printf("Group E , %f, %f,  %f, %f\n", BER1, V1, BER2, V2);                      //printing result    

    free(time);                                                                     //freeing the memory allocated to time        
    return 0;
}

int window_3ns(int *time, int count) {
    int start_pos = 0 , max_sum = 0;
    for (int i = 0; i <= 29000; i++) {                                              //going through all possible starting locations    
        int sum = 0;    
        for (int j = 0; j < count; j++) {                                           //going through the possible 3ns window
            if (time[j] >= i && time[j] < i + 3000)                                 
                sum++;
        }
        if (sum > max_sum) {                                                        //checking for max counts
            max_sum = sum;
            start_pos = i;
        }
    }
    return start_pos;
}

void without_g(int *time, int count, int start_pos, double *BER1, double *V1) {
    int c1 = 0, d1 = 0, c2 = 0;
    for (int i = 0; i < count; i++) {   
        if (time[i] >= start_pos && time[i] < start_pos + 1000)                     //counting the number of points in C1 bin
            c1++;       
        else if (time[i] >= start_pos + 1000 && time[i] < start_pos + 2000)         //counting the number of points in D1 bin
            d1++;
        else if (time[i] >= start_pos + 2000 && time[i] < start_pos + 3000)         //counting the number of points in C2 bin
            c2++;
    }
    *BER1 = (double)d1 / (c1 + d1 + c2);                                            //BER formula being implemented
    *V1 = 1.0 - ((double)d1 / (c1 + c2));                                           //Visibility formula being implemented
}       

void with_g(int *time, int count, int start_pos, double *BER2, double *V2) {
    int c1 = 0, d1 = 0, c2 = 0;
    for (int i = 0; i < count; i++) {
        if (time[i] >= start_pos && time[i] < start_pos + 950)                      //counting the number of points in C1 bin with guard bands
            c1++;
        else if (time[i] >= start_pos + 1050 && time[i] < start_pos + 1950)         //counting the number of points in D1 bin with guard bands
            d1++;
        else if (time[i] >= start_pos + 2050 && time[i] < start_pos + 3000)         //counting the number of points in C2 bin with guard bands
            c2++;
    }
    *BER2 = (double)d1 / (c1 + d1 + c2);                                            //BER formula being implemented
    *V2 = 1.0 - ((double)d1 / (c1 + c2));                                           //Visibility formula being implemented
}