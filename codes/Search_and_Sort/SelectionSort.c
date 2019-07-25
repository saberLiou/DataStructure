#include <stdio.h>
#include <stdlib.h>

#include "../input.h"
#include "../array.h"
#include "../swap.h"

#define RANDOM_RANGE 1000

void selectionSort(int [], int);

int main(void) {
	int amount = inputNumber("Enter the amount of numbers to generate a random number list: ", "Improper amount.\n");
	int list[amount], i;

	printf("List before sorted:\n");
	for (i = 0; i < amount; i++) {
		list[i] = rand() % RANDOM_RANGE;
		printf("%d ", list[i]);
	}
	printf("\n");

	selectionSort(list, amount);

	printf("List after sorted:\n");
	printIntegers(list, amount);

	return 0;
}

void selectionSort(int list[], int n) {
	int i, j, min, temp;
	int pass = 0;

	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[min]) min = j;
		}
		if (i != min) SWAP(list[i], list[min], temp);

		printf("Pass%d: ", ++pass);
		printIntegers(list, n);
	}
}