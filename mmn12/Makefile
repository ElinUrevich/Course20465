#==================================================
# File: Makefile
# Author: Elin Urevich
# ID: 314871518
# Purpose: Makefile for Magic Square Program.
#==================================================
CC = gcc
CFLAGS = -Wall -ansi -pedantic

magic_square: magic_square.c main.c
	$(CC) $(CFLAGS) -o magic_square magic_square.c main.c

clean:
	rm -f *.o magic_square
