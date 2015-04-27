#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/** All problems that are in this file */
int problem1();		// Multiples of 3 and 5
int problem2();		// Even Fibonacci numbers
int problem3();		// Largest prime factor
int problem4();
int problem5();
int problem6();
int problem7();
int problem8();
int problem9();
int problem10();
int problem11();
int problem12();	// Highly divisible triangular number
int problem13();	// Large sum
int problem14();

/** Helper functions */
int isPrime();

int main() {
	//problem1();
	//problem2(0, 1, 0);
	problem3();
	//problem4();
	//problem12();
	//problem13();
	getchar();
	return 0;
}

/** Problem 1: Multiples of 3 and 5 */
int problem1() {
	int i, sum = 0;
	for(i = 1; i < 1000; i++) {
		if(i % 3 == 0 || i % 5 == 0) sum += i;
	}
	printf("%d", sum);
	return 0;
}

/** Problem 2: Even fibonacci numbers */
int problem2(int i, int j, int sum) {
	int result;
	/* Base case:		If we reach a fibonacci value greater than 4 million, print the current sum. 
	/* Default case:	Find the value of the next fibonacci number. Check if even and recursively proceed */
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
	double largestFactor, i, number = 600851475143;
	for(i = 0; i < number / 2; i++) {
		double num = fmod(number / 2, i);
		if(num == 0 && isPrime(i) == 1) {
			printf("%f\n", i);
			largestFactor = i;
		}
	}
	printf("Largest Factor: %f\n", largestFactor);
	return 0;
}

/** Problem 12: Highly divisible triangular number */
int problem12() {
	/** Using a forumula of n-th number triangular number sequence, N(*(N+1)/2), we can find the n-th triangular
	number. It is sufficient to find the factors up to the square root of the current triangular number. Since we
	are looking for the square root, we can increment the number of factors by 2 each time.
		*/
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
	int array[100][51], i, j, c;
	/** Create a pointer to the file. */
	FILE *file;
	file = fopen("p13Numbers.txt", "r");
	/** If the file is empty, tell user. */
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

int isPrime(int j) {
	int i;
	if (j < 0) return 0;
	if (i % 2 == 0 || i % 3 == 0) return 0;
	for (i = 0; i * i <= j; i += 6) {
		if (j % i == 0 || j % (i + 2) == 0) return 0;
	}
	return 1;
}