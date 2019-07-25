#include <stdio.h>
#include <stdlib.h>

#include "../input.h"
#include "../array.h"
#include "../swap.h"

#define MAX_NUMBER 24

void permutation(char [], int, int);

unsigned long long count = 0;

int main(void) {
	char *list = inputLetters("Enter a list of letters: ");
	char *set = arrayToSet(list);

	printf("Set of letters you entered:\n");
	printCharacters(set, strlen(set), true);

	printf("All permutations of these letters:\n");
	permutation(set, 0, strlen(set) - 1);
	
	printf("Total amount of permutations: %llu\n", count);

	return 0;
}

void permutation(char list[], int i, int n) {
	int j;
	if (i == n) {
		count++;
		// printCharacters(list, n + 1, true);
		for (j = 0; j <= n; j++) {
			printf("%c ", list[j]);
		}
		printf("\n");
	}
	else {
		char temp;
		for (j = i; j <= n; j++) {
			SWAP(list[i], list[j], temp);
			permutation(list, i + 1, n);
			SWAP(list[i], list[j], temp);
		}
	}
}