CC=gcc
CFLAGS=-I. -Wall -Wextra -Wpedantic -Werror
DEPS = Triangle.h
OBJ = Trianglecalc.o Triangle.o
LIBS=-lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Trianglecalc: $(OBJ)
	$(CC) -o triangle $^ $(CFLAGS) $(LIBS)
