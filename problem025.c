#include<stdio.h>
#include<stdlib.h>

int add_big_int(int ar1, int ar2) {
	int *res;
	int carry = 0;
	int i;
	int value;

	res = malloc (1000 * sizeof(int));

	if (res == NULL) {
		printf("Error: could not allocate array.\n");
		return 0;
	}

	for (i = 1000; i >= 0; --i) {
		res[i] = ar1[i] + ar2[i];
		if (res[i] > 9) {
			res[i] -= 10;
			carry = 1;
		}
	}
	return *res;
}

int main() {

}
