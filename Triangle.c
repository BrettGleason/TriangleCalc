#include <stdio.h>

struct triangle_3s {
	int a, b, c;
};

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

	printf("Length of side a: %d, side b: %d, side c: %d\n", t1.a, t1.b, t1.c);

	return 0;
}