/*
Developer: Balasathya S
Roll No: EE24B093
Input(s): M (length of codeword) and N (length of block)
Output(s): Location of codeword (M) within a block of binary values (N)
Date: 03/09/2024
Used koala AI for understanding and part of the code
Hamming Distance is a measure of difference between two strings of equal length, specifically counting the number 
of positions where the corresponding elements differ. It’s often used in error correction to quantify how 
different two codewords (or blocks of data) are from each other.
Location (locn in the code) is the position in the block array where the substring most closely matching codeword 
starts. In other words, it's the starting index of the substring within block that has the smallest Hamming 
distance from codeword.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//To calculate the hamming distance between codeblock and block
int ham(int *codeword, int *block, int M) {
  int dist=0;
  for (int i=0; i<M; i++) {
    if (codeword[i] != block[i]) {
      dist++;
    }
  }
  return dist;
}

int main(int argc, char *argv[]) {
  int M = atoi(argv[1]);
  int N = atoi(argv[2]);
  if (M>N) {
    printf("M must be less than or equal to N\n");
    return 1;
  }
  
  //Initializing the random number generator with the current time, ensuring different random values on each run
  srand(time(NULL));
 
  //memory allocation for codeword and block arrays
  int *codeword = (int*)malloc(M*sizeof(int));
  int *block = (int*)malloc(N*sizeof(int));
  if (codeword == NULL || block == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
  }
  
  //Generating random values for codeword and block (between 0 and 1)
  for (int i=0; i<M; i++) {
    codeword[i]=rand()%2;
  }
  for (int i=0; i<N; i++) {
    block[i]=rand()%2;
  }
  
  //Finding minimum hamming distance
  /* int block[] = {1, 1, 0, 1, 0};
	If i = 0, then &block[1] + i points to block[1], which is 1.
	If i = 1, then &block[1] + i points to block[2], which is 0.
	If i = 2, then &block[1] + i points to block[3], which is 1. */

  int dist=0;
  int min_dist=M+1;  //Maximum possible distance is M
  int locn=-1;
  for (int i=0; i<=N-M; i++) {
    dist=ham(codeword, &block[1]+i, M);
    if (dist<min_dist) {
      min_dist=dist;
      locn=i+1;
    }
  }
  printf("EE24B093,%d,%d\n", locn, dist);
  
  //Free up the memory
  free(codeword);
  free(block);
  return 0;
}
