#include "../input.h"

#define RECURSIVE_AND_ITERATIVE 2
#define RECURSIVE_AND_ITERATIVE_AND_DYNAMIC_PROGRAMMING 3

#define RECURSIVE 1
#define ITERATIVE 2
#define DYNAMIC_PROGRAMMING 3

int pickComputingMethod(char *description, int how_many_methods) {
	int method = -1;
	char *full_description = strdup(description);
	char error[MAX_INPUT] = "Wrong method.\n";

	switch (how_many_methods) {
		case RECURSIVE_AND_ITERATIVE:
			strcat(full_description, "(1. Recursive, 2. Iterative): ");
			method = inputNumber(full_description, error);
			if (method == RECURSIVE || method == ITERATIVE) {
				return method;
			}
			break;
		case RECURSIVE_AND_ITERATIVE_AND_DYNAMIC_PROGRAMMING:
			strcat(full_description, "(1. Recursive, 2. Iterative, 3. Iterative by Dynamic Programming): ");
			method = inputNumber(full_description, error);
			if (method == RECURSIVE || method == ITERATIVE || method == DYNAMIC_PROGRAMMING) {
				return method;
			}
			break;
	}

	printf("%s", error);
	exit(1);
}