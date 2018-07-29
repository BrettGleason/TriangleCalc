#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

struct triangle_3s {
	int a, b, c;
};

int verify_triangle(struct triangle_3s);

double area_of_triangle(struct triangle_3s);

#endif
