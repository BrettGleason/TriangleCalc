#include <stdio.h>
#include <stdint.h>
#include "Triangle.h"

int main(void) {
	printf("Please enter the lengths of the triangle's sides in meters:\n");
	uint32_t a, b, c = 0;
	printf("Side a: ");
	scanf("%u", &a);
	printf("Side b: ");
	scanf("%u", &b);
	printf("Side c: ");
	scanf("%u", &c);

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
