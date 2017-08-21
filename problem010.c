#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 10: Summation of primes
 *  Ans: 142913828922
 */
 
int isPrime(int n) {
	unsigned int i;
	
	if (n <= 3) {
		return n > 1;
	}
	
	if (n % 2 == 0 || n % 3 == 0) {
		return 0;
	}
	
	for (i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) {
			return 0;
		}
	}
	
	return 1;
}

int main() {
	double sum = 0;
	double i;
	
	for(i = 0; i < 2000000; i++) {
		if(isPrime((int)i) == 1) {
			sum += i;
		}
	}
	
	printf("The sum of primes under 2 million: %f\n", sum);
	return 0;
}
