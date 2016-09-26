#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 6: Sum square differences
 *  Ans: 25164150
 */

int main() {
	unsigned int i, sumOfSquares = 0, squareOfSums = 0, result = 0;
	for(i = 1; i <= 100; i++) {
		sumOfSquares += (i * i);
		squareOfSums += i;
	}
	result = (squareOfSums * squareOfSums) - sumOfSquares;
	printf("Sum square difference: %d\n", result);
	return 0;
}
