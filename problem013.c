#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 13: Large sum
 *  Ans: 5537376230
 */
 
int main() {
	int array[100][50], i, j, c = 0;

	FILE *file;
	file = fopen("p13Numbers.txt", "r");
	if (file == NULL) {
		printf("This file does not exist.");
		exit(1);
	}
	
	for(i = 0; i < 100; i++) {
		for(j = 0; j < 50; j++) {
			fscanf(file, "%1d", &array[i][j]);
		}	
	}
	
	for(i = 1; i < 100; i++) {
		for(j = 49; j >= 0; j--) {
			if(j == 0) array[0][0] += array[i][0] + c;
			else {
				array[0][j] += array[i][j] + c;
				if(array[0][j] > 9) {
					array[0][j] -= 10;
					c = 1;	
				} else {
					c = 0;
				}
			}
		}
	}
	
	for(j = 0; j < 50; j++) printf("%d", array[0][j]);
	printf("\n");
	fclose(file);
	return 0;
}
