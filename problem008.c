#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 8: Largest product in a series
 *  Ans: 23514624000
 */
 
int main() {
	unsigned long prod = 1;
	unsigned long max = 0;
	int i;
	int j;
	int *array;

	FILE *file;
	file = fopen("p08Numbers.txt", "r");
	if (file == NULL) {
		printf("This file does not exist.");
		exit(1);
	}

	array = malloc(1000 * sizeof(int));
	if (array == NULL) {
		printf("Not enough memory. Terminating.");
		exit(1);
	}

	for(i = 0; i < 1000; i++) {
		fscanf(file, "%1d", &array[i]);
	}
	
	for(i = 0; i < (1000 - 13); i++) {
		for(j = 0; j < 13; j++) {
			prod *= array[i + j];
		}
		if(prod > max) {
			max = prod;
		}
		prod = 1;
	}
	
	free(array);
	fclose(file);
	printf("The largest product is: %lu\n", max);
	
	return 0;
}
