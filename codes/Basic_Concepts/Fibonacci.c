#include <stdio.h>
#include <stdlib.h>

#include "computing_method_picker.h"

unsigned long long fibonacciRecursive(int);
unsigned long long fibonacciIterative(int);
unsigned long long fibonacciIterativeByDynamicProgramming(int);

int main(void) {
	int method = pickComputingMethod("Choose the method to get Fibonacci number", RECURSIVE_AND_ITERATIVE_AND_DYNAMIC_PROGRAMMING);
	int number = inputNumber("Input the number: ", "Wrong number.\n");
	
	unsigned long long result;
	if (method == RECURSIVE) {
		result = fibonacciRecursive(number);
	}
	else if (method == ITERATIVE) {
		result = fibonacciIterative(number);
	}
	else {
		result = fibonacciIterativeByDynamicProgramming(number);
	}
	printf("The Fibonacci number: %llu\n", result);
	
	return 0;
}

unsigned long long fibonacciRecursive(int n) {
	return (n == 0 || n == 1) ? n : fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

unsigned long long fibonacciIterative(int n) {
	if (n == 0 || n == 1) return n;

	int first = 0, second = 1, i;
	unsigned long long result;
	for (i = 2; i <= n; i++) {
		result = first + second;
		first = second;
		second = result;
	}

	return result;
}

unsigned long long fibonacciIterativeByDynamicProgramming(int n) {
	int i;
	unsigned long long f[n + 1];
	f[0] = 0;
	f[1] = 1;

	for (i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}