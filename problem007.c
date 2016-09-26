#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 7: 10001st prime.
 *  Ans: 104743
 */
 
int isPrime(int n) {
	unsigned int i;
	if (n <= 3) return n > 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	for (i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return 0;
	}
	return 1;
}

int main() {
	unsigned int numOfPrimes = 0, i = 0;
	while(numOfPrimes < 10001) {
		if(isPrime(i) == 1) numOfPrimes++;
		i++;
	}
	i--;
	printf("10001st prime is: %d\n", i);
	return 0;
}
