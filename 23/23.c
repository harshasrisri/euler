#include <stdio.h>

#ifndef MAX
#define MAX 25000
#endif

char abundant[MAX];
char sums[MAX];
unsigned long long maxsum = (MAX * (MAX - 1)) >> 1;

int not_deficient (int num) {
	int i, sum;

	for (i = 1, sum = 0; i <= num >> 1; i++) {
		if (!(num % i)) sum += i;
		else continue;
		if (sum > num) {
			break;
		}
	}
	return (sum > num);
}

int main () {
	int i,j;

	for (i = 1; i < MAX; i++)
		if (!abundant[i] && not_deficient(i))
			for (j = i; j < MAX; j += i)
				abundant[j] = 1;


	for (i = 1; i < MAX; i++)
		for (j = 1; j < MAX; j++)
			if (i + j < MAX) {
				if (abundant[i] && abundant[j]) {
					if (!sums[i+j]) {
						sums[i + j] = 1;
						maxsum -= i+j;
					}
				}
			}
			else {
				break;
			}

	printf ("%llu\n", maxsum);
	return 0;
}
