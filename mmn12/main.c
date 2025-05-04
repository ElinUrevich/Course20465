/*==================================================
 * File: main.c
 * Author: Elin Urevich
 * ID: 314871518
 * Purpose: Main function to check whether a matrix
 *          is a basic magic square.
 *==================================================*/

 #include <stdio.h>
 #include "magic_square.h"
 
 int main(void) {
     int matrix[N][N];
     int extra;
 
     printf("Enter %d values (1 to %d) for a %dx%d matrix:\n", N * N, N * N, N, N);
 
     if (!read_matrix(matrix)) {
         return 1;
     }
 
     /* Check for extra input after reading N*N values */ 
     if (scanf("%d", &extra) == 1) {
         fprintf(stderr, "Error: Extra input values were provided.\n");
         return 1;
     }
 
     printf("\nThe matrix is:\n");
     print_matrix(matrix);

     if (!is_valid_range(matrix)) {
        printf("This is NOT a basic magic square: Matrix contains values out of the valid range (1-%d).\n", N * N);
        return 1;
    }
    
     if (!has_unique_values(matrix)) {
        printf("This is NOT a basic magic square.\n");
        return 1;
    }
 
     if (is_magic_square(matrix)) {
         printf("This is a basic magic square.\n");
     } else {
         printf("This is NOT a basic magic square.\n");
     }
 
     return 0;
 }
 