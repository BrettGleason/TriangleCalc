#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Triangle.h"

/* Iterate when new test cases are added */
#define TEST_COUNT 17

int main(void) {
	/* Becaues the get_side_length basically acts as a wrapper for the 
	 * validate_input() function to handle getting the input from stdin
	 * rather than as a command line argument, the test cases are the same
	 * as for validate_input() except with a newline character at the end
	 * of the entry */

	/* CONTENTS OF get_side_length_test_input.txt */
	char test[TEST_COUNT][1000] = {"-1000000000\n",
				  "-1\n",
				  "0\n",
				  "3\n",
				  "4294967295\n",
				  "5000000000\n",
				  "50 100\n",
				  "751.3\n",
				  "Rover\n",
				  "The quick brown fox jumped over the lazy dog\n",
				  "123456789101112131415161718192021222324252627282930\n",
				  "12345 678910 1112131415 1617181920\n",
				  "50,100,80\n",
				  "123AA\n",
				  "AA123\n",
				  "123 AA\n",
				  "AA 123\n"}; 
	uint32_t exp_result[TEST_COUNT] = {0,
					   0,
					   0,
					   1,
					   1,
					   0,
					   0,
					   0,
					   0,
					   0,
					   0,
					   0,
					   0,
					   0,
					   0,
					   0,
					   0};
	uint32_t result = 0, output = 0;

	for (uint32_t i = 0; i < TEST_COUNT; i++) {
		FILE* mock_stdin = fmemopen(test[i], strlen(test[i]), "r+");
		fprintf(mock_stdin, test[i]);
		rewind(mock_stdin);
		printf("Test %u input: %s", i + 1, test[i]);
		result = get_side_length(&output, mock_stdin);
		if (result == 1) {
			printf("input is valid, ");
		}
		else {
			printf("input is invalid, ");
		}
		if (result == exp_result[i]) {
			printf("TEST %u OK\n\n", i + 1);
		}
		else {
			printf("TEST %u FAILED\n\n", i + 1);
		}

		fclose(mock_stdin);
	}
	
	return 0;
}
