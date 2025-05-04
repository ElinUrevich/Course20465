/*==================================================
 * File: magic_square.h
 * Author: Elin Urevich
 * ID: 314871518
 * Purpose: Declarations for magic square functions.
 *==================================================*/

#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

#include <stdbool.h>

#define N 3  /* Matrix size */ 
/**
 * Reads a matrix of size N×N from standard input.
 * @param matrix The matrix to be filled.
 * @return true if the matrix was read successfully, false otherwise.
 */
bool read_matrix(int matrix[N][N]);

/**
 * Attempts to read a single integer value from standard input.
 * @param val Pointer to store the read value.
 * @return true if a valid integer was read, false otherwise.
 */
bool read_single_value(int* val);

/**
 * Clears the standard input buffer up to the next newline or EOF.
 */
void clear_input_buffer(void);

/**
 * Prints the matrix to standard output.
 * @param matrix The matrix to print.
 */
void print_matrix(int matrix[N][N]);

/**
 * Checks if all values in the matrix are within the valid range [1, N*N].
 * @param matrix The matrix to check.
 * @return true if all values are valid, false otherwise.
 */
bool is_valid_range(int matrix[N][N]);

/**
 * Checks if all values in the matrix are unique.
 * @param matrix The matrix to check.
 * @return true if all values are unique, false otherwise.
 */
bool has_unique_values(int matrix[N][N]);

/**
 * Determines if the matrix is a basic magic square.
 * @param matrix The matrix to check.
 * @return true if it is a basic magic square, false otherwise.
 */
bool is_magic_square(int matrix[N][N]);

#endif
