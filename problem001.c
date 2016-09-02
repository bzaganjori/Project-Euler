#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 1: Multiples of 3 and 5 
 *  Ans: 233168
 */

int main()  {
	int i, sum = 0;
	for (i = 1; i < 1000; i++) 
		if (i % 3 == 0 || i % 5 == 0) sum += i;
	printf("Sum: %d\n", sum);
	return 0;
}
