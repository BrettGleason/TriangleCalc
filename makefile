CC=gcc
CFLAGS=-I. -Wall -Wextra -Wpedantic -Werror
DEPS = Triangle.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Trianglecalc: Trianglecalc.o Triangle.o
	$(CC) -o triangle Trianglecalc.o Triangle.o -lm
