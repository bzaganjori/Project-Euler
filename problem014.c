#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 14: Largest Collatz sequence
 *  Ans: 5537376230
 */

int problem14A(int n, int count) {
	if (n == 1) {
		return count;
	} else if(n % 2 == 0) {
		n = n / 2;
		problem14A(n, count + 1);
	} else {
		n = (3 * n) + 1;
		problem14A(n, count + 1);
	}
}

int main() {
	int i, maxIndex = 0;
	double current, maxValue = 0;
	for(i = 0; i < 1000000; i++) {
		current = problem14A(i, 0);
		if(current > maxValue) {
			maxIndex = i;
			maxValue = current;
		}
	}
	printf("Index and value: %d %f\n", maxIndex, maxValue);
}
