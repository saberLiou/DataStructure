#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPositiveIntegerWithZero(char input[]) {
	int i;

	for (i = 0; i < strlen(input); i++) {
		if (!isdigit(input[i])) {
			return false;
		}
	}
	
	return true;
}