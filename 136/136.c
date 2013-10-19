#include <stdio.h>

#ifndef LIMIT
#define LIMIT 50000000
#endif

typedef unsigned long long ull;

unsigned int count = 0;

char position[LIMIT/8 + 1] = {0}, repeat[LIMIT/8 + 1] = {0};

void setbit (int num, char *array) {
	int pos = num / 8;
	int shift = num % 8;
	array[pos] |= 1 << shift;
}

int checkbit (int num, char *array) {
	int pos = num / 8;
	int shift = num % 8;
	return (array[pos] & (1 << shift));
}

void putbit (int n) {
	if (!checkbit(n, position)) {
		setbit (n, position);
		count++;
	}
	else if (!checkbit(n, repeat)) {
		setbit (n, repeat);
		count--;
	}
}

int main () {
	ull i, x, y, z, n;

	for (x = 1; x < LIMIT; x++) {
		for (i = 1; i < LIMIT; i++) {
			/* x = z + i + i; */
			/* y = z + i; */
			/* n = (x * x) - (y * y) - (z * z); */
			/* printf ("%llu = %llusq - %llusq - %llusq\n", n, x, y, z); */
			/* printf ("%llu\n", n); */
			/* if (n < LIMIT) putbit(n); */
			/* else break; */
			if ((n = (x - i) * (x - i) + (2 * i * i)) < LIMIT) putbit(n);
		}
	}

	/* for (i = 1; i < LIMIT; i++) */
	/* 	if ((checkbit(n, position)) && (!checkbit (i, repeat))) */
	/* 		printf ("%llu ", i); */
	fprintf (stderr, "%d\n", count);
	return 0;
}
