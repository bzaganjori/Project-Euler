#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 4: Largest palindrome product.
 *  Ans: 906609
 */
 
int isIntegerPalindrome(int i) {
	int dig;
	int num = i;
	int rev = 0;
	
	while (num > 0) {
		dig = num % 10;
		rev = rev * 10 + dig;
		num = num / 10;
	}
	
	return i == rev;
}

int main() {
	unsigned int i;
	unsigned int j;
	unsigned int product;
	
	for(i = 999; i > 900; i--) {
		for(j = 999; j > 900; j--) {
			product = i * j;
			if(isIntegerPalindrome(product) == 1) {
				printf("Largest palindrome product: %d\n", product);
				return 1;
			}
		}
	}
	
	return 0;
}
