#include <stdio.h>
#include "Triangle.c"

int main(void) {
	printf("Please enter the lengths of the triangle's sides:\n");
	printf("(Answer given in same units as side lengths, all lengths must be in same units.)\n");
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
	}

	return 0;
}
