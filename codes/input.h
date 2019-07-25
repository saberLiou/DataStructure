#include "validation.h"

#define MAX_INPUT 65535

int inputNumber(char *description, char error[]) {
	char number_input[MAX_INPUT];

	printf("%s", description);
	scanf("%s", number_input);
	fseek(stdin, 0, SEEK_END);	// flush buffer for the next scanf to use.
	
	if (!isPositiveIntegerWithZero(number_input)) {
		printf("%s", error);
		exit(1);
	}
	
	return atoi(number_input);
}

int *inputTwoNumbers(char *description, char error[]) {
	int *numbers = malloc(2 * sizeof(int));
	char first_number_input[MAX_INPUT], second_number_input[MAX_INPUT];

	printf("%s", description);
	scanf("%s %s", first_number_input, second_number_input);
	fseek(stdin, 0, SEEK_END);	// flush buffer for the next scanf to use.
	
	if (!isPositiveIntegerWithZero(first_number_input) || !isPositiveIntegerWithZero(second_number_input)) {
		printf("%s", error);
		exit(1);
	}

	numbers[0] = atoi(first_number_input);
	numbers[1] = atoi(second_number_input);
	return numbers;
}

char *inputLetters(char *description) {
	char *list = malloc(MAX_INPUT * sizeof(char));
	
	printf("%s", description);
	scanf("%s", list);

	return list;
}