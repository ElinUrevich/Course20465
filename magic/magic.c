/*==================================================
 * File: magic.c
 * Author: Elin Urevich
 * Purpose: Main function to check whether a matrix
 *          is a basic magic square.
 *==================================================*/

 #include <stdio.h>
 #include "square_utils.h"
 
 /**
  * Entry point of the program.
  * Reads a matrix from the user, validates it, prints it,
  * and determines whether it is a basic magic square.
  *
  * @return 0 on success, 1 on any error or invalid input.
  */
 int main(void) {
     int matrix[N][N];
     int extra;
 
     printf("Enter %d values (1 to %d) for a %dx%d matrix:\n", N * N, N * N, N, N);
 
     /* Read matrix values */
     if (!read_matrix(matrix)) {
         return 1;
     }
 
     /* Check for extra input after expected values */
     if (scanf("%d", &extra) == 1) {
         fprintf(stderr, "Error: Extra input values were provided.\n");
         return 1;
     }
 
     printf("\nThe matrix is:\n");
     print_matrix(matrix);
 
     /* Validate value range */
     if (!is_valid_range(matrix)) {
        printf("This is NOT a basic magic square: Matrix contains values out of the valid range (1-%d).\n", N * N);
         return 1;
     }
 
     /* Check for uniqueness */
     if (!has_unique_values(matrix)) {
        printf("This is NOT a basic magic square.\n");
         return 1;
     }
 
     /* Final check: is it a magic square? */
     if (is_magic_square(matrix)) {
         printf("This is a basic magic square.\n");
     } else {
         printf("This is NOT a basic magic square.\n");
     }
 
     return 0;
 }
 
