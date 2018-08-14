CC=gcc
IDIR=../include
CFLAGS=-I$(IDIR) -Wall -Wextra -Wpedantic -Werror
ODIR=obj

_DEPS = Triangle.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = trianglecalc.o Triangle.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_TESTOBJ = area_of_triangle_test.o verify_triangle_test.o validate_input_test.o get_side_length_test.o Triangle.o
TESTOBJ = $(patsubst %,$(ODIR)/%,$(_TESTOBJ))

LIBS=-lm

DESTDIR=
PREFIX=/usr/local
BINDIR=$(PREFIX)/bin
MANDIR=$(PREFIX)/share/man

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

trianglecalc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

tests: $(TESTOBJ)
	$(CC) -o area_of_triangle_test obj/area_of_triangle_test.o obj/Triangle.o $(CFLAGS) $(LIBS)
	$(CC) -o verify_triangle_test obj/verify_triangle_test.o obj/Triangle.o $(CFLAGS) $(LIBS)
	$(CC) -o validate_input_test obj/validate_input_test.o obj/Triangle.o $(CFLAGS) $(LIBS)
	$(CC) -o get_side_length_test obj/get_side_length_test.o obj/Triangle.o $(CFLAGS) $(LIBS)

test-all:
	./area_of_triangle_test > test_log.txt
	./verify_triangle_test >> test_log.txt
	./validate_input_test >> test_log.txt
	./get_side_length_test >> test_log.txt

.PHONY: tests test-all clean install uninstall

clean:
	rm $(ODIR)/*.o trianglecalc area_of_triangle_test verify_triangle_test validate_input_test get_side_length_test 

install: trianglecalc
	mkdir -p $(DESTDIR)$(BINDIR) # $(DESTDIR)$(MANDIR)/man1
	cp $< $(DESTDIR)$(BINDIR)/trianglecalc

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/trianglecalc
