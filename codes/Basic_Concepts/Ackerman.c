#include <stdio.h>
#include <stdlib.h>

#include "../input.h"

int ackerman(int, int);

int main(void) {
	int *numbers = inputTwoNumbers("Enter two numbers seperated by a space to get the Ackerman's function result: ", "Wrong number.\n");
	int m = numbers[0], n = numbers[1];

	printf("The Ackerman's function result of (%d, %d) is: %d\n", m, n, ackerman(m, n));

	return 0;
}

int ackerman(int m, int n) {
	return (m == 0) ? (n + 1) : ((n == 0) ? ackerman(m - 1, 1) : ackerman(m - 1, ackerman(m, n - 1)));
}