#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/** Author: 	Benjamin Zaganjori
		Toronto, Canada
		27/04/2015
*/

/** All problems that are in this file */
int problem1();		// Multiples of 3 and 5
int problem2();		// Even Fibonacci numbers
int problem3();		// Largest prime factor
int problem4();		// Largest plaindrome product
int problem5();		// Smallest multiple
int problem6();		// Sum square differences
int problem7();		// 10001st prime
int problem8();		// Largest product in a series
int problem9();		// Special pythagorean triplet
int problem10();	// Summation of primes
int problem11();	// Largest product in a grid
int problem12();	// Highly divisible triangular number
int problem13();	// Large sum
int problem14();	// Longest Collatz sequence
int problem15();	// Lattice paths
int problem16();	// Power digit sum
int problem17();	// Number letter counts
/* ################ */

/** Helper functions ###### */
int isPrime(int n);				// Checks if input integer is prime
int isIntegerPalindrome(int i);	// Checks if input integer is palindrome
/* ######################## */

int main() {
	//problem1();			//Ans: 233168
	//problem2(0, 1, 0);		//Ans: 4613732
	//problem3();			//Ans: 6857
	
	//TODO: problem4();		//Ans: 906609
	
	//problem5();			//Ans: 232792560
	//problem6();			//Ans: 25164150
	//problem7();			//Ans: 104743
	//problem8();			//Ans: 23514624000
	//problem9();			//Ans: 31875000
	//problem10();			//Ans: 142913828922
	//problem11();			//Ans: 70600674
	//problem12();			//Ans: 76576500
	//problem13();
	return 0;
}

/** Problem 1: Multiples of 3 and 5 */
int problem1() {
	int i, sum = 0;
	for(i = 1; i < 1000; i++) {
		if(i % 3 == 0 || i % 5 == 0) sum += i;
	}
	printf("Sum: %d\n", sum);
	return 0;
}

/** Problem 2: Even fibonacci numbers 
	Base case: If we reach a fibonacci value greater than 4 million, print the current sum. 
	Default case: Find the value of the next fibonacci number. Check if even and recursively proceed */
int problem2(int i, int j, int sum) {
	int result;
	if(j > 4000000) printf("Sum: %d", sum);
	else {
		result = i + j;
		if(result % 2 == 0) sum += result;
		problem2(j, result, sum);
	}
	return 0;
}

/** Problem 3: Largest prime factor */
int problem3() {
	unsigned long i, number = 600851475143, largestFactor;
	for (i = 0; i < number; i++) {
		if (isPrime(i) == 1 && number % i == 0) {
			printf("Current factor: %lu\n", i);
			largestFactor = i;
		}
	}
	printf("Largest Factor: %lu\n", largestFactor);
	return 0;
}

/** Problem 4: Largest palindrome product TODO: INCOMPLETE, SHOULD WORK 
BUT DOES NOT??? */
int problem4() {
	unsigned int i, j, product;
	for(i = 999; i > 900; i--) {
		for(j = 999; j > 900; j--) {
			product = i * j;
			if(isIntegerPalindrome(product) == 1) {
				printf("%d", product);
				break;
			}
		}
	}
	printf("Largest palindrome product: %d\n", product);
	return 0;
}

/** Problem 5: Smallest multiple 
Since were given an example at 2520, we can start there. Also, since we are 
looking for multiples from1 - 20, we can increment the number by 20 as 
optimization. This provides the most efficient answer. */
int problem5() {
	unsigned int i;
	for(i = 2540; ; i += 20) {
		if(i % 11 == 0 && i % 12 == 0 
			&& i % 13 == 0 && i % 14 == 0
			&& i % 15 == 0 && i % 16 == 0
			&& i % 17 == 0 && i % 18 == 0
			&& i % 19 == 0 && i % 20 == 0) {
				printf("Smallest even multiple: %d\n", i);
				break;
		}
	}
	return 0;
}

/** Problem 6: Sum square difference */
int problem6() {
	unsigned int i, sumOfSquares = 0, squareOfSums = 0, result = 0;
	for(i = 1; i <= 100; i++) {
		sumOfSquares += (i * i);
		squareOfSums += i;
	}
	result = (squareOfSums * squareOfSums) - sumOfSquares;
	printf("Sum square difference: %d\n", result);
	return 0;
}

/** Problem 7: 10001st prime 
Increment a counter and check if it is prime. Once we find the 10001st prime, 
op and subtract 1 from the answer as the i++ is still executed towards the 
end of the while loop.*/
int problem7() {
	unsigned int numOfPrimes = 0, i = 0;
	while(numOfPrimes < 10001) {
		if(isPrime(i) == 1) numOfPrimes++;
		i++;
	}
	i--;
	printf("10001st prime is: %d\n", i);
	return 0;
}

/** Largest product in a series
Read the numbers from a file and populate an array. Then find the largest 
product of 13 consecutive numbers. */
int problem8() {
	unsigned long prod = 1, max = 0;
	int i, j, *array;
	// Open and read file. Prompt if doesn't exist.
	FILE *file;
	file = fopen("p8Numbers.txt", "r");
	if (file == NULL) {
		printf("This file does not exist.");
		exit(1);
	}
	// Allocate memory for array. Prompt if no more memory.
	array = malloc(1000 * sizeof(int));
	if (array == NULL) {
		printf("Not enough memory. Terminating.");
		exit(1);
	}
	// Populate the array
	for(i = 0; i < 1000; i++) fscanf(file, "%1d", &array[i]);
	// Find products of all 13 consecutive numbers	
	for(i = 0; i < (1000 - 13); i++) {
		for(j = 0; j < 13; j++) {
			prod *= array[i + j];
		}
		// Check if the current product is larger than current max.
		if(prod > max) max = prod;
		// Reset product
		prod = 1;
	}
	fclose(file);
	printf("The largest product is: %lu\n", max);
	return 0;
}

/** Problem 9: Special Pythagorean triplet */
int problem9() {
	int a, b, c;
	for(a = 1; a < 500; a++) {
		for(b = a; b < 500; b++) {
			c = 1000 - (a + b);
			if ((a * a) + (b * b) == (c * c)) {
				if (a < b) printf("The triplet product is: %d\n", (a * b * c));
			}
		}
	}
	return 0;
}

/** Problem 10: Summation of primes */
int problem10() {
	double sum = 0, i;
	for(i = 0; i < 2000000; i++) {
		if(isPrime((int)i) == 1) sum += i;
	}
	printf("The sum of primes under 2 million: %f\n", sum);
	return 0;
}

/** Problem 11: Largest product in a grid 
Read the numbers from a file and populate the array. Then, keeping in mind the accessing of
non-existant memory, ie outside of the array, we focus our work between the 3rd index and 16th.
For each number, find the product of the next 4 adjecent numbers.*/
int problem11() {
	int array[20][20], i, j, k, product = 1, max = 0;
	FILE *file;
	file = fopen("p11Numbers.txt", "r");
	/* Check if file does not exist. */
	if(file == NULL) {
		printf("File does not exist.");
		exit(1);
	}
	/* Populate array */
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

/** Problem 12: Highly divisible triangular number 
Using a forumula of n-th number triangular number sequence, N(*(N+1)/2), we can find the n-th triangular number. It is sufficient to find the factors up to the square root of the current triangular number. Since we are looking for the square root, we can increment the number of factors by 2 each time. */
int problem12() {
	double i = 2, j, numOfFactors = 0, currentTriNum = 1;
	while(numOfFactors <= 500) {
		currentTriNum = i * (i + 1) / 2;
		numOfFactors = 2;
		for(j = 2; j < sqrt(currentTriNum); j++) {
			if((int)currentTriNum % (int)j == 0) numOfFactors += 2;
		}
		i++;
	}
	printf("%.0f %.0f\n", currentTriNum, numOfFactors);
	return 0;
}

/** Problem 13: Large sum. Find the first 10 digits of the sum of the 100, 50 digit long numbers.*/
int problem13() {
	int array[100][51], i, j;
	/** Create a pointer to the file. */
	FILE *file;
	file = fopen("p13Numbers.txt", "r");
	/** If the file is empty, prompt and exit. */
	if (file == NULL) {
		printf("This file does not exist.");
		exit(1);
	}
	/* Populate the array */
	for(i = 0; i < 100; i++) {
		for(j = 1; j < 51; j++) {
			fscanf(file, "%1d", &array[i][j]);
		}
	}

	for(i = 0; i < 100; i++) {
		for(j = 0; j < 51; j++) {
			printf("%d", array[i][j]);
		}
	}

	/*for(i = 0; i < 100; i++) {
		for(j = 51; j >= 0; j--) {
			if(j = 0) {
				array[
			}
			array[0][j] += array[i + 1][j] + c;
			if(array[0][j] > 9) {
				array[0][j] -= 10;
				c = 1;
			} else {
				c = 0;
			}
		}
	}*/

	fclose(file);
	return 0;
}

int problem14() {
	return 0;
}

/** Check if input number is prime or not */
int isPrime(int n) {
	unsigned int i;
	if (n <= 3) return n > 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	for (i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return 0;
	}
	return 1;
}

/** Checks if input integer is a palindrome. Returns 1 if palindrome. */
int isIntegerPalindrome(int i) {
	int reverse, remainder, temp;
	temp = i;
	while(temp != 0) {
		remainder = temp % 10;
		reverse = reverse * 10 + remainder;
		temp /= 10;
	}
	if(reverse == i) return 1;
	else return 0;
}


