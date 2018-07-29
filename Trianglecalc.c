#include <stdio.h>
#include "Triangle.c"

int main(void) {
	printf("Please enter the lengths of the triangle's sides in meters:\n");
	int a, b, c = 0;
	printf("Side a: ");
	scanf("%d", &a);
	printf("Side b: ");
	scanf("%d", &b);
	printf("Side c: ");
	scanf("%d", &c);

	struct triangle_3s t1 = {a, b, c};

	int tri_check = verify_triangle(t1);

	if (tri_check == 1) {
		printf("Triangle is valid.\n");
	}
	else if (tri_check == 0) {
		printf("Invalid triangle.\n");
		return -1;
	}

	double area = area_of_triangle(t1);

	printf("The area of the triangle is %f square meters.\n", area);

	return 0;
}
