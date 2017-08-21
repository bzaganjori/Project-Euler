#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/** bzaganjori
 *  Problem 12: Highly divisible triangular number
 *  Ans: 76576500
 */
 
int main() {
	double i = 2, j, numOfFactors = 0, currentTriNum = 1;
	while (numOfFactors <= 500) {
		currentTriNum = i * (i + 1) / 2;
		numOfFactors = 2;
		for (j = 2; j < sqrt(currentTriNum); j++) {
			if ((int)currentTriNum % (int)j == 0) {
				numOfFactors += 2;
			}
		}
		i++;
	}
	printf("%.0f %.0f\n", currentTriNum, numOfFactors);
	return 0;
}
