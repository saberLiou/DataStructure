#include <stdio.h>
#include <stdlib.h>

// #include "../string.h"
#include "../input.h"

#define SOURCE 'A'
#define AUXILIARY 'B'
#define DESTINATION 'C'

void hanoiTower(int, char, char, char);

unsigned long long count = 0;

int main(void) {
	char description[MAX_INPUT];
	// strcat(strcat(strcat(strcat(description, CHAR_TO_STRING(SOURCE)), " to "), CHAR_TO_STRING(DESTINATION)), ": ");
	snprintf(description, sizeof(description), "%s%c%s%c%s", "Enter the floors of Hanoi Tower to generate the steps of moving disks from ", SOURCE, " to ", DESTINATION, ": ");
	int floor = inputNumber(description, "Wrong number.\n");

	if (floor == 0) {
		printf("No disk to move.\n");
	}
	else {
		hanoiTower(floor, SOURCE, AUXILIARY, DESTINATION);
	}
	printf("Totally moving steps: %llu\n", count);

	return 0;
}

void hanoiTower(int n, char source, char auxiliary, char destination) {
	if (n == 1) {
		printf("Move disk 1 from %c to %c.\n", source, destination);
		count++;
	}
	else {
		hanoiTower(n - 1, source, destination, auxiliary);
		printf("Move disk %d from %c to %c.\n", n, source, destination);
		count++;
		hanoiTower(n - 1, auxiliary, source, destination);
	}
}