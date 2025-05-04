/*==================================================
 * File: square_utils.h
 * Author: Elin Urevich
 * ID: 314871518
 * Purpose: Function declarations for validating and 
 *          analyzing magic square matrices of size NxN.
 *==================================================*/

 #ifndef MAGIC_SQUARE_H
 #define MAGIC_SQUARE_H
 
 #include <stdbool.h>
 
 #define N 3  /**< Size of the square matrix (N x N) */
 
 /**
  * @brief Reads a matrix of size N×N from standard input.
  *
  * Expects exactly N*N integers separated by whitespace. 
  * Returns false if any value is not a valid integer, or if fewer than N*N values are provided.
  *
  * @param matrix The matrix to populate with input values.
  * @return true if the matrix was read successfully, false otherwise.
  */
 bool read_matrix(int matrix[N][N]);
 
 /**
  * @brief Attempts to read a single integer from standard input.
  *
  * If a non-integer is encountered, clears the buffer and reports an error.
  *
  * @param val Pointer to store the read value.
  * @return true if a valid integer was read, false otherwise.
  */
 bool read_single_value(int* val);
 
 /**
  * @brief Clears the input buffer until a newline or EOF.
  *
  * Used to recover from invalid input by discarding the rest of the line.
  */
 void clear_input_buffer(void);
 
 /**
  * @brief Prints the given matrix to standard output in a formatted grid.
  *
  * @param matrix The matrix to display.
  */
 void print_matrix(int matrix[N][N]);
 
 /**
  * @brief Checks if all values in the matrix are in the range [1, N*N].
  *
  * @param matrix The matrix to validate.
  * @return true if all values are within the valid range, false otherwise.
  */
 bool is_valid_range(int matrix[N][N]);
 
 /**
  * @brief Checks if all values in the matrix are unique.
  *
  * @param matrix The matrix to validate.
  * @return true if no value is repeated, false otherwise.
  */
 bool has_unique_values(int matrix[N][N]);
 
 /**
  * @brief Determines if the matrix is a basic magic square.
  *
  * A basic magic square has:
  *  - All values from 1 to N*N without repetition.
  *  - Equal sum of all rows, columns, and both diagonals.
  *
  * @param matrix The matrix to check.
  * @return true if the matrix is a basic magic square, false otherwise.
  */
 bool is_magic_square(int matrix[N][N]);
 
 #endif /* MAGIC_SQUARE_H */ 