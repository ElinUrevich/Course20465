#!/bin/bash
#==================================================
# File: run_tests.h
# Author: Elin Urevich
# Purpose: Convinient way to run tests for the magic_square program.
#          needs to be run from within tests folder after building the 
#          magic_square program. More details in the ReadMe.md .     
#==================================================

INPUT="test_cases.txt"
CASE=1

# Each test case will start with the headline and the comments below the test
while read -r line; do

    # Check if the line starts with '#' - means a new test case has begun
    if [[ $line == \#* ]]; then
        echo -e "\n========== Test $CASE =========="
        
        # Prints what the test should be validating 
        echo "$line"
        
        # Read the values specified for the test, print them and validate the program magic_square
        read -r input_line
	    echo "$input_line"
        echo "$input_line" | ../magic
        ((CASE++))
    fi

    

done < "$INPUT"
