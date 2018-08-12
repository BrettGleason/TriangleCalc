#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "Triangle.h"

#define TEST_COUNT 7

double close_enough(double test_value, double real_value); 

int main(void) {
	/* Assumptions:
	 *  - At this point in the code the input has been validated. The
	 *    triangle side lengths are positive nonzero integers that are <=
	 *    the upper limit of an unsigned 32 bit integer. */
	
	/* Test cases starting from small numbers and approaching the maximum
	 * size of a 32 bit unsigned integer (4294967295) */
	/* TODO: come up with better test set. Current test areas are whole
	 * numbers, leading to no floating point error. */

	struct triangle_3s test[TEST_COUNT] = { {1, 1, 1}, // Smallest possible triangle
						{3, 4, 5},
						{300, 400, 500},
						{30000, 40000, 50000},
						{3000000, 4000000, 5000000},
						{300000000, 400000000, 500000000},
						{UINT32_MAX, UINT32_MAX, UINT32_MAX} }; //Largest possible triangle

	double answer[TEST_COUNT] = {0.4330127019,
				     6.0,
				     60000.0,
				     600000000.0,
				     6000000000000.0,
				     60000000000000000.0,
				     7987674488751707136.0};
	uint32_t fail_count = 0;

	double area = 0.0;
	double result = 100.0;

	printf("********** area_of_triangle() test **********\n\n");

	for (uint32_t i = 0; i < (sizeof(test) / sizeof(struct triangle_3s)); i++) {
		printf("Test case %u: {%u, %u, %u}\n", i + 1, test[i].a, test[i].b, test[i].c);
		area = area_of_triangle(test[i]);
		result = close_enough(area, answer[i]);
		printf("Calculated area: %f\n", area);
		printf("Actual area: %f\n", answer[i]);
		printf("%% difference: %f%%\n", result);
		
		if (result < 1.0) {
			printf("Result is within 1%%, TEST %u OK\n\n", i + 1);
		}
		else {
			printf("Error in result is greater than 1%%, TEST %u FAILED\n\n", i + 1);
			fail_count++;
		}
	}

	if (fail_count == 0) {
		printf("ALL TEST CASES PASSED.\n");
	}
	else {
		printf("%u TEST CASE(S) FAILED.\n", fail_count);
	}

	printf("********** End of area_of_triangle() test **********\n\n");

	return fail_count;
}

double close_enough(double test_value, double real_value) {
	/* returns percent difference between two values */
	double diff = 100 * (fabs(test_value - real_value) / real_value);

	return diff;
}

