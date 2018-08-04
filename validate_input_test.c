#include <stdio.h>
#include <stdint.h>
#include "Triangle.h"

#define TEST_COUNT 17

int main(void) {

	char test[TEST_COUNT][1000] = {"-1000000000",
				  "-1",
				  "0",
				  "3",
				  "4294967295",
				  "5000000000",
				  "50 100",
				  "751.3",
				  "Rover",
				  "The quick brown fox jumped over the lazy dog",
				  "123456789101112131415161718192021222324252627282930",
				  "12345 678910 1112131415 1617181920",
				  "50,100,80",
				  "123AA",
				  "AA123",
				  "123 AA",
				  "AA 123"};
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
	uint32_t result, output = 0;

	for (uint32_t i = 0; i < TEST_COUNT; i++) {
		printf("Test %u input: %s\n", i + 1, test[i]);
		result = validate_input(test[i], &output);
		if (result == 1) {
			printf("input is valid, ");
		}
		else {
			printf("input is invalid, ");
		}
		if (result == exp_result[i]) {
			printf("TEST %u OK\n", i + 1);
		}
		else {
			printf("TEST %u FAILED\n", i + 1);
		}
	}
	
	return 0;
}
