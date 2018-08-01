#include <stdio.h>
#include <stdint.h>
#include "Triangle.h"

int main(void) {
	printf("Please enter the lengths of the triangle's sides in meters:\n");
	char side_a[11], side_b[11], side_c[11];
	uint32_t a, b, c = 0;
	printf("Side a: ");
	a = get_side_length(side_a);
	printf("Side b: ");
	b = get_side_length(side_b);
	printf("Side c: ");
	c = get_side_length(side_c);

	struct triangle_3s t1 = {a, b, c};

	uint32_t tri_check = verify_triangle(t1);

	if (tri_check == 1) {
		printf("Triangle is valid.\n");
	}
	else if (tri_check == 0) {
		printf("Invalid triangle.\n");
		return -1;
	}

	double area = area_of_triangle(t1);

	printf("The area of the triangle is %.2f square meters.\n", area);

	return 0;
}
