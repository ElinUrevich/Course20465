/*==================================================
 * File: magic_square.c
 * Author: Elin Urevich
 * ID: 314871518
 * Purpose: Implementation of functions for checking
 *          and printing a magic square matrix.
 *==================================================*/

 #include <stdio.h>
 #include <stdbool.h>
 #include "magic_square.h"
 
 void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

bool read_single_value(int* val) {
    int result = scanf("%d", val);

    if (result != 1) {
    {
        /* Non-integer input */
        if (result == 0) {
            fprintf(stderr, "Error: Invalid input, not an integer.\n");
            clear_input_buffer();
            return false;
        }

        return false;
        }   
    }
    return true;
}

bool read_matrix(int matrix[N][N]) {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (!read_single_value(&matrix[i][j])) {

                /* Explicit EOF check*/
                if (feof(stdin)) {  
                    fprintf(stderr, "Error: Only %d values provided (need %d)\n", (i*N)+j, N*N);
                }

                return false;
            
                
            }
        }
    }   
    return true;
}

 
 void print_matrix(int matrix[N][N]) {
     int i, j;
     for (i = 0; i < N; ++i) {
         for (j = 0; j < N; ++j) {
             printf("%4d", matrix[i][j]);
         }
         printf("\n");
     }
 }
 
 bool is_valid_range(int matrix[N][N]) {
     int i, j;
     for (i = 0; i < N; ++i) {
         for (j = 0; j < N; ++j) {
             if (matrix[i][j] < 1 || matrix[i][j] > N * N) {
                 return false;
             }
         }
     }
     return true;
 }
 
 bool has_unique_values(int matrix[N][N]) {
     bool seen[N * N + 1];
     int i, j;
     for (i = 0; i <= N * N; ++i) {
         seen[i] = false;
     }
 
     for (i = 0; i < N; ++i) {
         for (j = 0; j < N; ++j) {
             if (seen[matrix[i][j]])
                 return false;
             seen[matrix[i][j]] = true;
         }
     }
     return true;
 }
 
 bool is_magic_square(int matrix[N][N]) {
     int magic_sum = 0;
     int expected_sum;
     int i, j;
 
     for (j = 0; j < N; ++j)
         magic_sum += matrix[0][j];
 
     expected_sum = N * (N * N + 1) / 2;
     if (magic_sum != expected_sum)
         return false;
 
     for (i = 1; i < N; ++i) {
         int row_sum = 0;
         for (j = 0; j < N; ++j)
             row_sum += matrix[i][j];
         if (row_sum != magic_sum)
             return false;
     }
 
     for (j = 0; j < N; ++j) {
         int col_sum = 0;
         for (i = 0; i < N; ++i)
             col_sum += matrix[i][j];
         if (col_sum != magic_sum)
             return false;
     }
 
     {
         int diag1 = 0, diag2 = 0;
         for (i = 0; i < N; ++i) {
             diag1 += matrix[i][i];
             diag2 += matrix[i][N - 1 - i];
         }
         if (diag1 != magic_sum || diag2 != magic_sum)
             return false;
     }
 
     return true;
 }
 