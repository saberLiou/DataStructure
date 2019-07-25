#include <stdio.h>
#include <stdlib.h>

#include "../input.h"

#define USE_LINEAR false

unsigned long long exponentialOn(int, int);
unsigned long long exponentialOLogN(long double, int);

int main(void) {
	int *numbers = inputTwoNumbers("Enter two numbers (a and b) seperated by a space to calculate a to the power of b: ", "Wrong number.\n");
	int a = numbers[0], b = numbers[1];
    if (a == 0) {
        printf("Number a must be positive integer.\n");
    }
    else {
        printf("The %d to the power of %d is: %llu\n", a, b, USE_LINEAR ? exponentialOn(a, b) : exponentialOLogN((long double) a, b));
    }

    return 0;
}

unsigned long long exponentialOn(int a, int b) {
    return (b == 0) ? 1 : exponentialOn(a, b - 1) * a;
}

unsigned long long exponentialOLogN(long double a, int b) {
    long double ld = (b % 2 == 0) ? 1.0 : a;
    return (b < 2) ? ld : ld * exponentialOLogN(a * a, b / 2);
}