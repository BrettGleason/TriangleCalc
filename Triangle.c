#include <stdio.h>

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

	printf("Length of side a: %d, side b: %d, side c: %d\n", a, b, c);

	return 0;
}
