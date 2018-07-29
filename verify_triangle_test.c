#include <stdio.h>
#include "Triangle.h"

int main(void) {
	/* Assumptions:
	 *  - At this point in the code the input has been validated. The
	 *    triangle side lengths are non-negative integers that are smaller
	 *    than the upper limit of an unsigned 32 bit integer. */

	struct triangle_3s test1 = {3, 4, 5}; // Valid triangle, right triangle
	struct triangle_3s test2 = {1000, 1000, 1000}; // Valid triangle, equilateral triangle
	struct triangle_3s test3 = {200, 200, 390}; // Valid triangle, isoceles triangle
	struct triangle_3s test4 = {50, 60, 70}; // Valid triangle, scalene
	struct triangle_3s test5 = {100, 50, 30}; // Invalid, side A too long
	struct triangle_3s test6 = {50, 100, 30}; // Invalid, side B too long
	struct triangle_3s test7 = {50, 30, 100}; // Invalid, side C too long

	int result = 2;
	
	result = verify_triangle(test1);
	printf("Test case 1: {%d, %d, %d}\n", test1.a, test1.b, test1.c);
	if (result == 1) {
		printf("Triangle is valid, TEST 1 OK\n");
	}
	else if (result == 0) {
		printf("Triangle is invalid, TEST 1 FAILED\n");
	}
	else {
		printf("Result out of bounds, TEST 1 FAILED\n");
	}
		
	result = verify_triangle(test2);
	printf("Test case 2: {%d, %d, %d}\n", test2.a, test2.b, test2.c);
	if (result == 1) {
		printf("Triangle is valid, TEST 2 OK\n");
	}
	else if (result == 0) {
		printf("Triangle is invalid, TEST 2 FAILED\n");
	}
	else {
		printf("Result out of bounds, TEST 2 FAILED\n");
	}

	result = verify_triangle(test3);
	printf("Test case 3: {%d, %d, %d}\n", test3.a, test3.b, test3.c);
	if (result == 1) {
		printf("Triangle is valid, TEST 3 OK\n");
	}
	else if (result == 0) {
		printf("Triangle is invalid, TEST 3 FAILED\n");
	}
	else {
		printf("Result out of bounds, TEST 3 FAILED\n");
	}

	result = verify_triangle(test4);
	printf("Test case 4: {%d, %d, %d}\n", test4.a, test4.b, test4.c);
	if (result == 1) {
		printf("Triangle is valid, TEST 4 OK\n");
	}
	else if (result == 0) {
		printf("Triangle is invalid, TEST 4 FAILED\n");
	}
	else {
		printf("Result out of bounds, TEST 4 FAILED\n");
	}

	result = verify_triangle(test5);
	printf("Test case 5: {%d, %d, %d}\n", test5.a, test5.b, test5.c);
	if (result == 0) {
		printf("Triangle is invalid, TEST 5 OK\n");
	}
	else if (result == 1) {
		printf("Triangle is valid, TEST 5 FAILED\n");
	}
	else {
		printf("Result out of bounds, TEST 5 FAILED\n");
	}

	result = verify_triangle(test6);
	printf("Test case 6: {%d, %d, %d}\n", test6.a, test6.b, test6.c);
	if (result == 0) {
		printf("Triangle is invalid, TEST 6 OK\n");
	}
	else if (result == 1) {
		printf("Triangle is valid, TEST 6 FAILED\n");
	}
	else {
		printf("Result out of bounds, TEST 6 FAILED\n");
	}

	result = verify_triangle(test7);
	printf("Test case 7: {%d, %d, %d}\n", test7.a, test7.b, test7.c);
	if (result == 0) {
		printf("Triangle is invalid, TEST 7 OK\n");
	}
	else if (result == 1) {
		printf("Triangle is valid, TEST 7 FAILED\n");
	}
	else {
		printf("Result out of bounds, TEST 7 FAILED\n");
	}

	return 0;
}
