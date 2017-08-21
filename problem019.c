#include<stdio.h>
#include<stdlib.h>

int main() {
	int month[12]={31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i;
	int j;
	int day = 1;
	int sunday = 1;
	
	// For all years between our scope...
	for (i = 1900; i < 2000; ++i) {
		
		// If leap year, Feb has 28, else 29.
		if (i % 4 == 0)
			month[1] = 29;
		else
			month[1] = 28;
			
		for (j = 0; j < 12; ++j) {
			if (day % 7 == 0) sunday++;
			day += month[j];			
		}
	}
	
	printf("%d\n", sunday);
	return 0;
}


