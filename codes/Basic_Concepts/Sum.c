#include <stdio.h>
#include <stdlib.h>

#include "computing_method_picker.h"

unsigned long long sumRecursive(int);
unsigned long long sumIterative(int);

int main(void) {
	int method = pickComputingMethod("Choose the method to calculate total addition from 1 to a number", RECURSIVE_AND_ITERATIVE);
	int number = inputNumber("Input the number: ", "Wrong number.\n");

	if (number > 0) {
		printf("The total addition from 1 to the number %d is %llu\n", number, (method == RECURSIVE) ? sumRecursive(number) : sumIterative(number));
	}
	else {
		printf("The total addition of 0 is 0\n");
	}
	
	return 0;
}

unsigned long long sumRecursive(int n) {
	return (n == 0) ? 0 : sumRecursive(n - 1) + n;
}

unsigned long long sumIterative(int n) {
	int i;
	unsigned long long result = 0;

	for (i = 0; i <= n; i++) {
		result += i;
	}

	return result;
}