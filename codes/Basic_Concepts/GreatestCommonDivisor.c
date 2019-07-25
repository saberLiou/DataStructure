#include <stdio.h>
#include <stdlib.h>

#include "../input.h"

int gcd(int, int);

int main(void) {
	int *numbers = inputTwoNumbers("Enter two numbers seperated by a space to get their greatest common divisor: ", "Wrong number.\n");
	int a = numbers[0], b = numbers[1];

	printf("The greatest common divisor of (%d, %d) is: %d\n", a, b, gcd(a, b));

	return 0;
}

int gcd(int a, int b) {
	return (a % b == 0) ? b : gcd(b, a % b);
}