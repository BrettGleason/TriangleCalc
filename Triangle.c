#include "Triangle.h"
#include <math.h>

int verify_triangle(struct triangle_3s triangle) {
	/* Return 1 if triangle is valid, else return 0 */
	/* Use Triangle Inequality Theorem to make sure triangle is valid. */
	if (triangle.a + triangle.b > triangle.c &&
			triangle.a + triangle.c > triangle.b &&
			triangle.b + triangle.c > triangle.a) {
		return 1;
	}
	else {
		return 0;
	}
}

double area_of_triangle(struct triangle_3s triangle) {
	/* Calculate area using Herons's formula */
	double s = (triangle.a + triangle.b + triangle.c) / 2;
	double area = sqrt(s*(s-triangle.a)*(s-triangle.b)*(s-triangle.c));
	return area;
}
