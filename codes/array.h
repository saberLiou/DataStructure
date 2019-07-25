void printIntegers(int array[], unsigned int array_length) {
	int i;
	for (i = 0; i < array_length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void printCharacters(char array[], unsigned int array_length, bool without_escape) {
	int i;
	for (i = 0; i < array_length; i++) {
		if (without_escape && array[i] == '\0') {
			// printf("%c ", '@');
			break;
		}
		printf("%c ", array[i]);
	}
	printf("\n");
}

char *arrayToSet(char *list) {
	unsigned long int list_length = strlen(list);
	char *temp_set = malloc(list_length * sizeof(char));

	bool in_set = false;
	int i, j, set_length = 0;
	for (i = 0; i < list_length; i++) {
		j = 0;
		while (j < list_length && temp_set[j] != '\0') {
			if (list[i] == temp_set[j]) {
				in_set = true;
			}
			j++;
		}

		if (!in_set) {
			set_length++;
			temp_set[j] = list[i];
		}
		else {
			in_set = false;
		}
	}

	char *set = malloc(set_length * sizeof(char));
	for (i = 0; i < set_length; i++) {
		set[i] = temp_set[i];
	}
	return set;
}