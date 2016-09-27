#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 2: Even fibonacci numbers 
 *  Ans: 4613732
 */

int problem2(int i, int j, int sum) {
	int result;

	if (j > 4000000) {
		printf("Sum: %d \n", sum);
	} else {
		result = i + j;
		if (result % 2 == 0) {
			sum += result;
		}
		problem2(j, result, sum);
	}
	return 0;
}

int main() {
	problem2(0, 1, 0);
}
