#include <stdio.h>
#include <stdint.h>
#include "Triangle.h"

int main(void) {
	/* Assumptions:
	 *  - At this point in the code the input has been validated. The
	 *    triangle side lengths are non-negative integers that are smaller
	 *    than the upper limit of an unsigned 32 bit integer. */

	/* TODO: test function for case where triangle side lengths are
	 * individually smaller than the 32 bit integer limit but add up to be
	 * larger */

	/* Increment test_count each time a test case is added */
	const uint32_t test_count = 7;

	/* If I try to declare the test array using test_count as the size, I
	 * get a compilation error because the size of the array is not known
	 * at compile time. Values are initialized this way because trying to 
	 * initialize them as in the commented lines below threw another
	 * compile time error. I'd like to figure out a way to initialize these
	 * values that is more similar to the commented lines so that the test
	 * case reasoning can be described. */
	struct triangle_3s test[7] = {  {3, 4, 5},
		                        {1000, 1000, 1000},
				        {200, 200, 390},
					{50, 60, 70},
					{100, 50, 30},
					{50, 100, 30},
					{50, 30, 100} };
	uint32_t exp_result[test_count]; // 0 for invalid triangle, 1 for valid triangle

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

	

	uint32_t result = 2;
	
	for (int i = 0; i < (sizeof(test) / sizeof(struct triangle_3s)); i++) {
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
