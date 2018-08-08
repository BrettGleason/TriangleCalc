#include "Triangle.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

uint32_t verify_triangle(struct triangle_3s triangle) {
	/* Return 1 if triangle is valid, else return 0 */
	/* Use Triangle Inequality Theorem to make sure triangle is valid. */

	/* ovf variables establish if the addition of two side lengths will
	 * overflow the maximum size of a 32 bit unsigned integer */
	uint32_t ovf_ab, ovf_ac, ovf_bc = 0;
	if (UINT32_MAX - triangle.a < triangle.b) {
		ovf_ab = 1;
	}
	if (UINT32_MAX - triangle.a < triangle.c) {
		ovf_ac = 1;
	}
	if (UINT32_MAX - triangle.b < triangle.c) {
		ovf_bc = 1;
	}
	
	/* In the case where two side lengths don't add to a larger value
	 * than the unsigned 32 bit int max, the test on the left side of 
	 * the OR will work. If the addition of two side lengths overflows
	 * the UINT_MAX, the result must be larger than the third side which
	 * is limited to UINT_MAX during data collection. */
	if ( (triangle.a + triangle.b > triangle.c || ovf_ab == 1 ) &&
			(triangle.a + triangle.c > triangle.b || ovf_ac == 1) &&
			(triangle.b + triangle.c > triangle.a || ovf_bc == 1) ) {
		return 1;
	}
	else {
		return 0;
	}
}

double area_of_triangle(struct triangle_3s triangle) {
	/* Calculate area using Herons's formula */

	/* Cast integers to double here because integer division truncates */
	double s = ((double)triangle.a + (double)triangle.b + (double)triangle.c) / 2;
	double area = sqrt(s*(s-triangle.a)*(s-triangle.b)*(s-triangle.c));
	return area;
}

uint32_t get_side_length(char* side_length, uint32_t* output, FILE* in_stream) {
	/* Read string from stdin, convert to a valid 32 bit unsigned integer 
	 * and store the result at side_length.
	 * If the user input is valid, return 1
	 * If the user input is invalid, return 0 */
	
	char input[sizeof(side_length)];
	/* output stores converted integer value. If the result is invalid then
	 * validate_input() will return 0 */
	uint32_t result = 0;
	strcpy(input, fgets(side_length, sizeof(side_length), in_stream));
	result = validate_input(input, output);

	return result;
}

uint32_t validate_input(char* input, uint32_t* output) {
	/* Converts the string from the user into a valid unsigned 32 bit integer.
	 * If the user input is valid, return 1
	 * If the user input is invalid, return 0 */

	/* Stores the address at which strtol stops reading the string */
	char *endpoint;
	/* Using a long int for this value because the strtol function is built
	 * in and very handy but it returns a long int. It's easier to check that
	 * the converted number is within the bounds of an unsigned 32 bit integer
	 * than to roll my own strtol that returns a uint_32t. */
	long int converted_number = strtol(input, &endpoint, 10);

	/* Make sure that strtol read the whole string - implying the input
	 * contained only numbers and not a combination of letters and numbers
	 * endpoint will be '\0' if passed as a command line argument or '\n'
	 * if string is from user input. */
	if (*endpoint != '\0' && *endpoint != '\n') {
		return 0;
	}

	if (converted_number > 0 && converted_number <= UINT32_MAX) {
		*output = converted_number;
	}
	else {
		return 0;
	}

	return 1;
}


