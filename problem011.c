#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 11: Largest product in a grid
 *  Ans: 70600674
 */
 
int main() {
	int array[20][20], i, j, k, product = 1, max = 0;

	FILE *file;
	file = fopen("p11Numbers.txt", "r");
	if(file == NULL) {
		printf("File does not exist.");
		exit(1);
	}

	for(i = 0; i < 20; i++) {
		for(j = 0; j < 20; j++) {
			fscanf(file, "%d", &array[i][j]);
		}
	}

	for(i = 3; i < 17; i++) {
		for(j = 3; j < 17; j++) {
			for(k = 0; k < 4; k++) product *= array[i - k][j - k];
			if(product > max) max = product;
			product = 1;
			for(k = 0; k < 4; k++) product *= array[i][j - k];
			if(product > max) max = product;
			product = 1;
			for(k = 0; k < 4; k++) product *= array[i + k][j - k];
			if(product > max) max = product;
			product = 1;
			for(k = 0; k < 4; k++) product *= array[i + k][j];
			if(product > max) max = product;
			product = 1;
			for(k = 0; k < 4; k++) product *= array[i + k][j + k];
			if(product > max) max = product;
			product = 1;
			for(k = 0; k < 4; k++) product *= array[i][j + k];
			if(product > max) max = product;
			product = 1;
			for(k = 0; k < 4; k++) product *= array[i - k][j + k];
			if(product > max) max = product;
			product = 1;
			for(k = 0; k < 4; k++) product *= array[i - k][j];
			if(product > max) max = product;
			product = 1;
		}
	}
	printf("The largest product in grid is: %d\n", max);
	return 0;
}
