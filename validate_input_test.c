#include <stdio.h>
#include <stdint.h>
#include "Triangle.h"

int main(void) {
	test1 = -1000000000; 	// Large negative number
	test2 = -1;		// Small negative number
	test3 = 0;		// Zero
	test4 = 3;		// Small positive number
	test5 = 4294967295;	// Limit of 32 bit integers
	test6 = 5000000000;	// Larger than 32 bit integer limit
	test7 = 50 100;		// Two numbers at once
	test8 = 751.3;		// Floating point instead of integer
	test9 = "Rover";	// string instead of integer
	test10 = "The quick brown fox jumped over the lazy dog"; // Long string with spaces
	test11 = 123456789101112131415161718192021222324252627282930; // Long integer
	test12 = 12345 678910 1112131415 1617181920; // Long integer with spaces
	test13 = "123AA";	// Numbers and letters
	test14 = "123 AA";	// Numbers and letters with a space
	
	return 0;
}
