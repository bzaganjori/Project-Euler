#include<stdio.h>
#include<stdlib.h>

/** bzaganjori
 *  Problem 5: Smallest multiple
 *  Ans: 232792560
 */

int main() {
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
