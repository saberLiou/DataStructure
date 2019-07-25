#include <stdio.h>
#include <stdlib.h>

#include "computing_method_picker.h"

#define MAX_NUMBER 20

unsigned long long factorialRecursive(int);
unsigned long long factorialIterative(int);

int main(void) {
	int method = pickComputingMethod("Choose the method to calculate factorial", RECURSIVE_AND_ITERATIVE);
	int number = inputNumber("Enter a number to get its factorial: ", "Wrong number.\n");

	if (number > MAX_NUMBER) {
		printf("The number %d is too big to calculate its factorial.\n", number);
	}
	else {
		printf("The factorial of the number %d is: %llu\n", number, (method == RECURSIVE) ? factorialRecursive(number) : factorialIterative(number));
	}

	return 0;
}

unsigned long long factorialRecursive(int n) {
	return (n == 0) ? 1 : factorialRecursive(n - 1) * n;
}

unsigned long long factorialIterative(int n) {
	unsigned long long result = 1, i;

	for (i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}