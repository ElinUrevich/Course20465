
========== Test 1 ==========
# Test 1: Valid magic square but with tabs and spaces
8 1 6 3      5 7 4   9     2
Enter 9 values (1 to 9) for a 3x3 matrix:

The matrix is:
   8   1   6
   3   5   7
   4   9   2
This is a basic magic square.

========== Test 2 ==========
# Test 2: Duplicate values
8 1 6 3 5 7 4 9 9
Enter 9 values (1 to 9) for a 3x3 matrix:

The matrix is:
   8   1   6
   3   5   7
   4   9   9
This is NOT a basic magic square.

========== Test 3 ==========
# Test 3: Value out of range
8 1 6 3 5 7 4 0 2
Enter 9 values (1 to 9) for a 3x3 matrix:

The matrix is:
   8   1   6
   3   5   7
   4   0   2
This is NOT a basic magic square: Matrix contains values out of the valid range (1-9).

========== Test 4 ==========
# Test 4: Value out of range
8 1 -99 3 5 7 4 1 2
Enter 9 values (1 to 9) for a 3x3 matrix:

The matrix is:
   8   1 -99
   3   5   7
   4   1   2
This is NOT a basic magic square: Matrix contains values out of the valid range (1-9).

========== Test 5 ==========
# Test 5: Not a magic square
1 2 3 4 5 6 7 8 9
Enter 9 values (1 to 9) for a 3x3 matrix:

The matrix is:
   1   2   3
   4   5   6
   7   8   9
This is NOT a basic magic square.

========== Test 6 ==========
# Test 6: Valid magic square with extra input
8 1 6 3 5 7 4 9 2 100 200
Error: Extra input values were provided.
Enter 9 values (1 to 9) for a 3x3 matrix:

========== Test 7 ==========
# Test 7: Square with not enough input
8 1 6 3 5 7 4      9
Error: Only 8 values provided (need 9)
Enter 9 values (1 to 9) for a 3x3 matrix:

========== Test 8 ==========
# Test 8: Magic square with a char input instead of int
8 1 6 3 5 7 a  9 2
Error: Invalid input, not an integer.
Enter 9 values (1 to 9) for a 3x3 matrix:
