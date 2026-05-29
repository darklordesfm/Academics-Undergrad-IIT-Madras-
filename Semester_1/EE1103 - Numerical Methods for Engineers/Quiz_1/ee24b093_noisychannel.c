/*
Developer: Balasathya Saravanan
Roll Number: EE24B093
Date: 06/09/2024
Input(s): M, N, Seed, L, p
Output(s): Location of minimum and minimum hamming distance
Help Used: Used ChatGPT for syntax and part of the code
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

//Defining Hamming Distance function
int hamming_dist(int *a, int *b, int M) {
  int dist=0;
  for (int i=0; i<M; i++) {
    if (a[i]!=b[i]) {
      dist++;
    }
  }
  return dist;
}

//Adding Noise and flipping the bits in the block
void noise(int *block, int Q, float p) {
  for (int i=0; i<Q; i++) {
    if ((float)rand()/RAND_MAX<p) {
      block[i]=1-block[i];
    }
  }
}
    
//Main Function
int main(int argc, char *argv[]) {
  if (argc!=6) {
    printf("Error: Invalid number of arguments\n");
    return 1;
  }
  
  int M = atoi(argv[1]);
  int N = atoi(argv[2]);
  int Seed = atoi(argv[3]);
  int L = atoi(argv[4]);
  float p = atof(argv[5]);
  
  //Conditions for inputs
  if (M<=0||N<=0||Seed<0||L<=0||p<=0.0||M>=1000||N>=10000||p>=0.3||L>=N) {
    printf("Error: Invalid values of arguments\n");
    return 1;
  }
  
  //Memory Allocation for block and code
  int *code=(int*)malloc(M*sizeof(int));
  int *block=(int*)malloc(N*sizeof(int));
  if (code==NULL||block==NULL) {
        printf("Memory allocation failed\n");
        return 1;
  }
  
  
  // Seed random number generator
  srand(Seed);
  
  //Generate random code and block
  for (int i=0; i<M; i++) {
    code[i]=rand()%2;
  }
  for (int i=0; i<N; i++) {
    block[i]=rand()%2;
  }
  
  //Insert code into block at position L
  for (int i=0; i<M; i++) {
    block[L+i]=code[i];
  }
  
  //Calling noise function
  noise(block,N,p);
  
  //Calculating hamming distance
  int dist=0;
  int min_dist=M; 
  int min_locn=0;
  for (int i=0; i<=N-M; i++) {
    dist=hamming_dist(code, block+i, M);
    if (dist<min_dist) {
      min_dist=dist;
      min_locn=i;
    }
  }
  printf("EE24B093,%d,%d\n",min_locn+1, min_dist);
  free(code);
  free(block);
  return 0;
}
    
  
  
  
