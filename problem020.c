#include<stdio.h>
#include<stdlib.h>

#define MAX 500

int print(int res[]) {
	int i = 0;
	int count = 0;
	for (i = 0; i < MAX; i++) {
		if (!count && res[i]) 
			count = 1;
		if (count)
			printf("%d", res[i]);
	}
}

void factorial(int res[], int n) {
	if (!n) return;
	int i = 0;
	int carry = 0;
	for (i = MAX - 1; i >= 0; --i) {
		res[i] = (res[i] * n) + carry;
		carry = res[i] / 10;
		res[i] %= 10;
	}
	
	factorial(res, n - 1);
}

int main() {
	int input;
	int res[MAX];
	res[MAX - 1] = 1;
	printf("Factorial input: ");
	scanf("%d", &input);
	factorial(res, input);
	print(res);
	return 0;
}


