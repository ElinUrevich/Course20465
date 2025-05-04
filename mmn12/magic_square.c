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
 
 /**
  * @brief Clears the input buffer to handle invalid or leftover input.
  *
  * This function discards characters from the input buffer until a newline 
  * character ('\n') or EOF is encountered.
  */
 void clear_input_buffer(void) {
     int c;
     while ((c = getchar()) != '\n' && c != EOF) {}
 }
 
 /**
  * @brief Reads a single integer value from the user.
  *
  * If the input is not a valid integer, the buffer is cleared and an error 
  * message is printed.
  *
  * @param val Pointer to an integer where the input value will be stored.
  * @return true if a valid integer was read, false otherwise.
  */
 bool read_single_value(int* val) {
     int result = scanf("%d", val);
 
     if (result != 1) {
         if (result == 0) {
             fprintf(stderr, "Error: Invalid input, not an integer.\n");
             clear_input_buffer();
         }
         return false;
     }
     return true;
 }
 
 /**
  * @brief Reads an N×N matrix from standard input.
  *
  * Each value is validated as an integer using read_single_value().
  *
  * @param matrix The matrix to populate.
  * @return true if all N×N values were read successfully, false otherwise.
  */
 bool read_matrix(int matrix[N][N]) {
     int i, j;
     for (i = 0; i < N; ++i) {
         for (j = 0; j < N; ++j) {
             if (!read_single_value(&matrix[i][j])) {
                 if (feof(stdin)) {
                     fprintf(stderr, "Error: Only %d values provided (need %d)\n", (i * N) + j, N * N);
                 }
                 return false;
             }
         }
     }
     return true;
 }
 
 /**
  * @brief Prints the N×N matrix in a formatted grid.
  *
  * Each value is printed with width 4 for alignment.
  *
  * @param matrix The matrix to print.
  */
 void print_matrix(int matrix[N][N]) {
     int i, j;
     for (i = 0; i < N; ++i) {
         for (j = 0; j < N; ++j) {
             printf("%4d", matrix[i][j]);
         }
         printf("\n");
     }
 }
 
 /**
  * @brief Validates that all values in the matrix are within [1, N*N].
  *
  * @param matrix The matrix to validate.
  * @return true if all values are in the valid range, false otherwise.
  */
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
 
 /**
  * @brief Checks whether all values in the matrix are unique.
  *
  * Uses a boolean array to track occurrences of values.
  *
  * @param matrix The matrix to validate.
  * @return true if all values are unique, false otherwise.
  */
 bool has_unique_values(int matrix[N][N]) {
     bool seen[N * N + 1] = { false };
     int i, j;
 
     for (i = 0; i < N; ++i) {
         for (j = 0; j < N; ++j) {
             int val = matrix[i][j];
             if (seen[val])
                 return false;
             seen[val] = true;
         }
     }
     return true;
 }
 
 /**
  * @brief Determines whether a matrix is a basic magic square.
  *
  * A basic magic square has all values from 1 to N*N (no duplicates),
  * and the sums of all rows, columns, and both diagonals are equal.
  *
  * @param matrix The matrix to validate.
  * @return true if the matrix is a magic square, false otherwise.
  */
 bool is_magic_square(int matrix[N][N]) {
     int magic_sum = 0, diag1 = 0, diag2 = 0, sum = 0;
     int expected_sum = N * (N * N + 1) / 2;
     int i, j;
 
     /* Calculate the sum of the first row */
     for (j = 0; j < N; ++j)
         magic_sum += matrix[0][j];
 
     if (magic_sum != expected_sum)
         return false;
 
     /* Check sums of all rows */
     for (i = 1; i < N; ++i) {
        sum = 0;
         for (j = 0; j < N; ++j)
             sum += matrix[i][j];
         if (sum != magic_sum)
             return false;
     }
 
     /* Check sums of all columns */
     for (j = 0; j < N; ++j) {
        sum = 0;
         for (i = 0; i < N; ++i)
             sum += matrix[i][j];
         if (sum != magic_sum)
             return false;
     }
 
     /* Check sums of both diagonals */
     
     
     for (i = 0; i < N; ++i) {
         diag1 += matrix[i][i];
         diag2 += matrix[i][N - 1 - i];
     }
     if (diag1 != magic_sum || diag2 != magic_sum)
         return false;
 
     return true;
 } 