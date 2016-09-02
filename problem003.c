#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 3: Largest prime factor
 *  Ans: 6857
 */
 
int isPrime(int n) {
	unsigned int i;
	if (n <= 3) return n > 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	for (i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0) return 0;
	return 1;
}

int main() {
	unsigned long i;
	unsigned long number = 600851475143;
	unsigned long largestFactor;
	for (i = 0; i < number; i++) {
		if (isPrime(i) == 1 && number % i == 0) {
			printf("Current factor: %lu\n", i);
			largestFactor = i;
		}
	}
	printf("Largest Factor: %lu\n", largestFactor);
	return 0;
}
