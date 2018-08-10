CC=gcc
CFLAGS=-I. -Wall -Wextra -Wpedantic -Werror
DEPS = Triangle.h
OBJ = Trianglecalc.o Triangle.o
TESTOBJ = area_of_triangle_test.o verify_triangle_test.o validate_input_test.o get_side_length_test.o Triangle.o
LIBS=-lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Trianglecalc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

tests: $(TESTOBJ)
	$(CC) -o area_of_triangle_test area_of_triangle_test.o Triangle.o $(CFLAGS) $(LIBS)
	$(CC) -o verify_triangle_test verify_triangle_test.o Triangle.o $(CFLAGS) $(LIBS)
	$(CC) -o validate_input_test validate_input_test.o Triangle.o $(CFLAGS) $(LIBS)
	$(CC) -o get_side_length_test get_side_length_test.o Triangle.o $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm *.o $(objects) Trianglecalc
