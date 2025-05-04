#==================================================
# File: Makefile
# Author: Elin Urevich
# ID: 314871518
# Purpose: Makefile for Magic Square Program.
#==================================================
CC = gcc
CFLAGS = -Wall -ansi -pedantic

magic_square: square_utils.c magic.c
	$(CC) $(CFLAGS) -o magic square_utils.c magic.c

clean:
	rm -f *.o magic
