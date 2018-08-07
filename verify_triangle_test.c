#include <stdio.h>
#include <stdint.h>
#include "Triangle.h"

#define TEST_COUNT 10 // Increment TEST_COUNT each time a test case is added

int main(void) {
	/* Assumptions:
	 *  - At this point in the code the input has been validated. The
	 *    triangle side lengths are positive, nonzero integers that are smaller
	 *    than the upper limit of an unsigned 32 bit integer. */


	/* If I try to declare the test array using test_count as the size, I
	 * get a compilation error because the size of the array is not known
	 * at compile time. Values are initialized this way because trying to 
	 * initialize them as in the commented lines below threw another
	 * compile time error. I'd like to figure out a way to initialize these
	 * values that is more similar to the commented lines so that the test
	 * case reasoning can be described. */
	struct triangle_3s test[TEST_COUNT] = { {3, 4, 5},
		                        	{1000, 1000, 1000},
				        	{200, 200, 390},
						{50, 60, 70},
						{100, 50, 30},
						{50, 100, 30},
						{50, 30, 100},
						{UINT32_MAX, UINT32_MAX, UINT32_MAX},
						{UINT32_MAX, 10000, 10000},
						{UINT32_MAX, UINT32_MAX, 50000}, };

	uint32_t exp_result[TEST_COUNT]; // 0 for invalid triangle, 1 for valid triangle

	// test[0] = {3, 4, 5}; // Valid triangle, right triangle
	exp_result[0] = 1;
	// test[1] = {1000, 1000, 1000}; // Valid triangle, equilateral triangle
	exp_result[1] = 1;
	// test[2] = {200, 200, 390}; // Valid triangle, isoceles triangle
	exp_result[2] = 1;
	// test[3] = {50, 60, 70}; // Valid triangle, scalene
	exp_result[3] = 1;
	// test[4] = {100, 50, 30}; // Invalid, side A too long
	exp_result[4] = 0;
	// test[5] = {50, 100, 30}; // Invalid, side B too long
	exp_result[5] = 0;
	// test[6] = {50, 30, 100}; // Invalid, side C too long
	exp_result[6] = 0;
	// test[7] = {UINT32_MAX, UINT32_MAX, UINT32_MAX}; // Largest valid triangle
	exp_result[7] = 1;
	// test[8] = {UINT32_MAX, 10000, 10000}; // Invalid triangle with integer overflow
	exp_result[8] = 0;
	// test[9] = {UINT32_MAX, UINT32_MAX, 50000}; // Valid triangle with integer overflow
	exp_result[9] = 1;

	

	uint32_t result = 2;
	
	for (uint32_t i = 0; i < (sizeof(test) / sizeof(struct triangle_3s)); i++) {
		printf("Test case %u: {%u, %u, %u}\n", i + 1, test[i].a, test[i].b, test[i].c);
		result = verify_triangle(test[i]);
		if (result == 1) {
			printf("Triangle is valid, ");
		}
		else if (result == 0) {
			printf("Triangle is invalid, ");
		}
		else {
			printf("Result out of bounds, ");
		}
		if (result == exp_result[i]) {
			printf("TEST %u OK\n", i + 1);
		}
		else {
			printf("TEST %u FAILED\n", i + 1);
		}
	}

	return 0;
}
