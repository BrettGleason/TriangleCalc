#include <stdio.h>
#include <stdint.h>
#include "Triangle.h"

int main(int argc, char *argv[]) {
	uint32_t a, b, c = 0;
	uint32_t result_a, result_b, result_c = 0;
	if (argc == 1) {
		printf("Please enter the lengths of the triangle's sides in meters:\n");
		printf("Side a: ");
		result_a = get_side_length(&a, stdin);
		if (result_a == 0) {
			printf("Invalid side length provided.\n");
			return -1;
		}
		printf("Side b: ");
		result_b = get_side_length(&b, stdin);
		if (result_b == 0) {
			printf("Invalid side length provided.\n");
			return -1;
		}
		printf("Side c: ");
		result_c = get_side_length(&c, stdin);
		if (result_c == 0) {
			printf("Invalid side length provided.\n");
			return -1;
		}
	}
	else if (argc == 4) {
		result_a = validate_input(argv[1], &a);
		result_b = validate_input(argv[2], &b);
		result_c = validate_input(argv[3], &c);

		if (result_a == 0 || result_b == 0 || result_c == 0) {
			printf("Invalid arguments provided.\n");
			return -1;
		}
	}
	else {
		printf("Incorrect number of arguments provided.\n");
		return -2;
	}

	struct triangle_3s t1 = {a, b, c};

	uint32_t tri_check = verify_triangle(t1);

	if (tri_check == 0) {
		printf("Invalid triangle.\n");
		return -3;
	}

	double area = area_of_triangle(t1);

	printf("The area of the triangle is %.2f square meters.\n", area);

	return 0;
}
