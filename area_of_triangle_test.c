#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "Triangle.h"

double close_enough(double test_value, double real_value); 

int main(void) {
	/* Assumptions:
	 *  - At this point in the code the input has been validated. The
	 *    triangle side lengths are non-negative integers that are smaller
	 *    than the upper limit of an unsigned 32 bit integer. */
	
	/* Test cases starting from small numbers and approaching the maximum
	 * size of a 32 bit unsigned integer (4294967295) */
	/* TODO: come up with better test set. Current test areas are whole
	 * numbers, leading to no floating point error. */
	struct triangle_3s test1 = {3, 4, 5};
	double answer1 = 6.0;
	struct triangle_3s test2 = {300, 400, 500};
	double answer2 = 60000.0;
	struct triangle_3s test3 = {30000, 40000, 50000};
	double answer3 = 600000000.0;
	struct triangle_3s test4 = {3000000, 4000000, 5000000};
	double answer4 = 6000000000000.0;
	struct triangle_3s test5 = {300000000, 400000000, 500000000};
	double answer5 = 60000000000000000.0;
	struct triangle_3s test6 = {3000000000, 4000000000, 4000000000};
	double answer6 = 600000000000000000000.0;

	double area = area_of_triangle(test1);
	double result = close_enough(area, answer1);
	printf("Test 1 triangle: {%u, %u, %u}\n", test1.a, test1.b, test1.c);
	printf("Calculated area: %f\n", area);
	printf("Actual area: %f\n", answer1);
	printf("%% difference: %f%%\n", result);
	if (result < 1.0) {
		printf("Result is within 1%%, TEST 1 OK\n\n");
	}
	else {
		printf("Error in result is greater than 1%%, TEST 1 FAILED\n\n");
	}

	area = area_of_triangle(test2);
	result = close_enough(area, answer2);
	printf("Test 2 triangle: {%u, %u, %u}\n", test2.a, test2.b, test2.c);
	printf("Calculated area: %f\n", area);
	printf("Actual area: %f\n", answer2);
	printf("%% difference: %f%%\n", result);
	if (result < 1.0) {
		printf("Result is within 1%%, TEST 2 OK\n\n");
	}
	else {
		printf("Error in result is greater than 1%%, TEST 2 FAILED\n\n");
	}
	
	area = area_of_triangle(test3);
	result = close_enough(area, answer3);
	printf("Test 3 triangle: {%u, %u, %u}\n", test3.a, test3.b, test3.c);
	printf("Calculated area: %f\n", area);
	printf("Actual area: %f\n", answer3);
	printf("%% difference: %f%%\n", result);
	if (result < 1.0) {
		printf("Result is within 1%%, TEST 3 OK\n\n");
	}
	else {
		printf("Error in result is greater than 1%%, TEST 3 FAILED\n\n");
	}
	
	area = area_of_triangle(test4);
	result = close_enough(area, answer4);
	printf("Test 4 triangle: {%u, %u, %u}\n", test4.a, test4.b, test4.c);
	printf("Calculated area: %f\n", area);
	printf("Actual area: %f\n", answer4);
	printf("%% difference: %f%%\n", result);
	if (result < 1.0) {
		printf("Result is within 1%%, TEST 4 OK\n\n");
	}
	else {
		printf("Error in result is greater than 1%%, TEST 4 FAILED\n\n");
	}

	area = area_of_triangle(test5);
	result = close_enough(area, answer5);
	printf("Test 5 triangle: {%u, %u, %u}\n", test5.a, test5.b, test5.c);
	printf("Calculated area: %f\n", area);
	printf("Actual area: %f\n", answer5);
	printf("%% difference: %f%%\n", result);
	if (result < 1.0) {
		printf("Result is within 1%%, TEST 5 OK\n\n");
	}
	else {
		printf("Error in result is greater than 1%%, TEST 5 FAILED\n\n");
	}
	
	area = area_of_triangle(test6);
	result = close_enough(area, answer6);
	printf("Test 6 triangle: {%u, %u, %u}\n", test6.a, test6.b, test6.c);
	printf("Calculated area: %f\n", area);
	printf("Actual area: %f\n", answer6);
	printf("%% difference: %f%%\n", result);
	if (result < 1.0) {
		printf("Result is within 1%%, TEST 6 OK\n\n");
	}
	else {
		printf("Error in result is greater than 1%%, TEST 6 FAILED\n\n");
	}

	return 0;
}

double close_enough(double test_value, double real_value) {
	/* returns percent difference between two values */
	double diff = 100 * (fabs(test_value - real_value) / real_value);

	return diff;
}

