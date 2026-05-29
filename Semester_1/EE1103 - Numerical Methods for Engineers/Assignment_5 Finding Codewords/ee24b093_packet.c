/*
Developer: Balasathya
Roll No: EE24B093
Date: 05/09/2024
Used CHATGPT for a part of the code
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate_transmission(int M, int N, int P) {
    int *code_word = (int*)malloc(M * sizeof(int));
    int *message = (int*)malloc(2 * M * sizeof(int));
    
    srand(time(0));
    
    // Generate random code_word
    for (int i = 0; i < M; i++) {
        code_word[i] = rand() % 2;
    }

    // Generate random message
    for (int i = 0; i < 2 * M; i++) {
        message[i] = rand() % 2;
    }

    int successcount = 0;

    for (int p = 0; p < P; p++) {
        int *block = (int*)calloc(N, sizeof(int)); // Initialize block to 0

        // Choose random insertion point
        int point_of_insertion = rand() % (N - 3 * M + 1);

        // Copy code_word into block starting at point_of_insertion
        for (int i = 0; i < M; i++) {
            block[point_of_insertion + i] = code_word[i];
        }

        // Copy message into block starting at point_of_insertion + M
        for (int i = 0; i < 2 * M; i++) {
            block[point_of_insertion + M + i] = message[i];
        }

        // Verify if the packet matches at the insertion point
        int match = 1;
        for (int i = 0; i < M; i++) {
            if (block[point_of_insertion + i] != code_word[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            for (int i = 0; i < 2 * M; i++) {
                if (block[point_of_insertion + M + i] != message[i]) {
                    match = 0;
                    break;
                }
            }
        }

        // Increment success count if a match was found
        if (match) {
            successcount++;
        }

        free(block); // Free memory for the block
    }

    // Calculate efficiency
    double efficiency = (double)successcount / P;
    printf("EE24B093,%d,%d,%d,%.3f\n", M, N, P, efficiency);

    // Free allocated memory for code_word and message
    free(code_word);
    free(message);
}

int main(int argc, char *argv[]) {
    int M = atoi(argv[1]);
    int N = atoi(argv[2]);
    int P = atoi(argv[3]);
    
    // Ensure N is large enough to hold the packet
    if (3 * M > N) {
        printf("3M must be less than or equal to N\n");
        return 1;
    }
  
    simulate_transmission(M, N, P);

    return 0;
}
