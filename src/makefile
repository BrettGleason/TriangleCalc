CC=gcc
IDIR=../include
CFLAGS=-I$(IDIR) -Wall -Wextra -Wpedantic -Werror
ODIR=obj

_DEPS = Triangle.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Trianglecalc.o Triangle.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_TESTOBJ = area_of_triangle_test.o verify_triangle_test.o validate_input_test.o get_side_length_test.o Triangle.o
TESTOBJ = $(patsubst %,$(ODIR)/%,$(_TESTOBJ))

LIBS=-lm

$(OBJ): $(ODIR)/%o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Trianglecalc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

tests: $(TESTOBJ)
	$(CC) -o area_of_triangle_test area_of_triangle_test.o Triangle.o $(CFLAGS) $(LIBS)
	$(CC) -o verify_triangle_test verify_triangle_test.o Triangle.o $(CFLAGS) $(LIBS)
	$(CC) -o validate_input_test validate_input_test.o Triangle.o $(CFLAGS) $(LIBS)
	$(CC) -o get_side_length_test get_side_length_test.o Triangle.o $(CFLAGS) $(LIBS)

test-all:
	./area_of_triangle_test > test_log.txt
	./verify_triangle_test >> test_log.txt
	./validate_input_test >> test_log.txt
	./get_side_length_test >> test_log.txt

.PHONY: clean

clean:
	rm *.o $(objects) Trianglecalc area_of_triangle_test verify_triangle_test validate_input_test get_side_length_test
