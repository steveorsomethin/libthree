#ifndef TESTS_H
#define TESTS_H

struct test_def {
	char *name;
	int (*func)(void);
};

void run_tests(struct test_def *tests, int num_tests)
{
	int failures = 0;
	printf("Running %d tests...\n", num_tests);

	for (int i = 0; i < num_tests; i++) {
		struct test_def *curr = tests++;

		printf("Test %s: ", curr->name);
		if (curr->func()) {
			failures++;
		} else {
			printf("SUCCEEDED\n");
		}
	}

	printf("Finished. %d of %d tests successful.\n", num_tests - failures, num_tests);
}

#define TEST_ASSERT(expr)										\
	do {														\
		if (!(expr)) {											\
			printf("Assertion FAILED in %s on line %d: %s\n",	\
					__FILE__,									\
					__LINE__,									\
					#expr);										\
			return 1;											\
		} else {												\
			return 0;											\
		}														\
	} while (0)

#define TEST(name) \
	int test_##name()

#define TEST_ADD(name) \
	{#name, &test_##name},

#define START_TESTS struct test_def TESTS[] = {

#define END_TESTS {0, 0} };	\
	run_tests(&TESTS[0], (sizeof(TESTS) / sizeof(TESTS[0])) - 1);

#endif //TESTS_H