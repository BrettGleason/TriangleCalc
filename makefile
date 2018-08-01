CC=gcc
CFLAGS=-I. -Wall -Wextra -Wpedantic -Werror
Trianglecalc: Trianglecalc.o Triangle.o
	$(CC) -o triangle Trianglecalc.o Triangle.o -lm
