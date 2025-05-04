This archive contains test cases for the `magic_square` project.

In order to run the tests described below you need to do is:

1. Build the magic_square programm (from ../)
   $ make
 
2. run from within this folder:
   $ chmod +x ./run_tests.sh && ./run_tests.sh


Each test case is designed to check a specific edge condition:
1. Valid magic square:
   - Input: 8 1 6 3 5 7 4 9 2
   - Expected: Program recognizes it as a basic magic square.

2. Duplicate values:
   - Input: Last value (9) is repeated.
   - Expected: Program should report an error due to duplicate values.

3. Value out of range:
   - Input includes a 0 which is outside valid range 1–9.
   - Expected: Program should report a range error.

4. Value out of range:
   - Input includes a -99 which is outside valid range 1–9.
   - Expected: Program should report a range error.

5. Not a magic square:
   - Values are 1 through 9 but sums don't match.
   - Expected: Program should say it's not a magic square.

6. Valid magic square with extra input:
   - Extra values (100 200) appear after matrix input.
   - Expected: Program should print a warning about extra input.

7. Not enough input:
   - Only 8 values provided.
   - Expected: Program should print error about invalid input.

8. There is a value which isn't of type int:
   - Input has the char 'a'.
   - Expected: Program should print error about invalid input.


