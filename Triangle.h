#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include <stdint.h>

struct triangle_3s {
	uint32_t a, b, c;
};

uint32_t verify_triangle(struct triangle_3s);

double area_of_triangle(struct triangle_3s);

uint32_t get_side_length(char* side_length, uint32_t* output);

uint32_t validate_input(char* input, uint32_t* output);

#endif
