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
	uint32_t fail_count = 0;
	uint32_t result, output = 0;

	printf("********** validate_input() test **********\n\n");

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
			printf("TEST %u OK\n\n", i + 1);
		}
		else {
			printf("TEST %u FAILED\n\n", i + 1);
			fail_count++;
		}
	}

	if (fail_count == 0) {
		printf("ALL TEST CASES PASSED.\n");
	}
	else {
		printf("%u TEST_CASE(S) FAILED.\n", fail_count);
	}

	printf("********** End of validate_input() test **********\n\n");
	
	return fail_count;
}
