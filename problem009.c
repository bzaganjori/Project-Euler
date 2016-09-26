#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 9: Special pythagorean triplet
 *  Ans: 31875000
 */
 
int main() {
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
