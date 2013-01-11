#include <stdio.h>

struct test_def {
	char *name;
	char *desc;
	int (*func)(void);
};

void run_tests(struct test_def *tests, size_t num_tests)
{
	int failures = 0;
	printf("Running %d tests...\n", num_tests);

	for (int i = 0; i < num_tests; i++) {
		struct test_def *curr = tests[i];

		if (curr->func()) {
			printf("Test %s - %s: FAILED due to %s", curr->name, curr->desc, fmted_error);
			failures++;
		}
	}

	printf("\n\nFinished. %d of %d tests successful.\n", num_tests - failures, num_tests);
}

#define TEST_ASSERT(expr)										\
	do {														\
		if (!(expr)) {											\
			fprintf(stderr,										\
					"Assertion failed in %s on line %d: %s\n",	\
					__FILE__,									\
					__LINE__,									\
					#expr);										\
			return 1;											\
		}														\
	} while (0)

#define TEST_ADD(name, desc, func) \
	{#name, desc, &test_##func},

#define START_TESTS struct test_def TESTS[] = {

#define END_TESTS {0, 0, 0, 0} };	\
	run_tests(&TESTS[0], (sizeof(TESTS) / sizeof(TESTS[0])) - 1);