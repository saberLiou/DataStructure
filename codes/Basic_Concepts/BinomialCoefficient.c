#include <stdio.h>
#include <stdlib.h>

#include "../input.h"

int binomialCoefficient(int, int);

int main(void) {
	int *numbers = inputTwoNumbers("Enter two numbers seperated by a space to get their combinations amount: ", "Wrong number.\n");
	int n = numbers[0], m = numbers[1];

	printf("The combinations amount of (%d, %d) is: %d\n", n, m, (n < m) ? 0 : binomialCoefficient(n, m));

	return 0;
}

int binomialCoefficient(int n, int m) {
	return (m == 0 || n == m) ? 1 : binomialCoefficient(n - 1, m) + binomialCoefficient(n - 1, m - 1);
}