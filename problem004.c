#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 4: Largest palindrome product.
 *  Ans: 906609
 */
 
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

int main() {
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
