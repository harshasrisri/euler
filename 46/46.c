# include <stdio.h>
# include <string.h>

#ifndef LIMIT
#define LIMIT 10000
#endif

unsigned char prime[LIMIT] = {' '};
unsigned int squares[LIMIT];

#define is_prime(x) (!prime[x])

void prepare_primes () {
	unsigned int i = 2, j, temp;

	prime[0] = prime[1] = 1;

	for (i = 3; i <= LIMIT; i+=2) {
		if (!is_prime(i)) continue;
		j = 2;
		while ((temp = i * j) < LIMIT) {
			prime[temp] = 1;
			j++;
		}
	}
}

int is_square (int a) {
	int i;
	for (i = 1; i < LIMIT; i++)
		if (squares[i] == a)
			return 1;
	return 0;
}

int main () {
	int i, j;

	prepare_primes();

	for (i = 0; i < LIMIT; i++)
		squares[i] = i * i;

	for (i = 9; i < LIMIT; i+=2) {
		if (is_prime(i)) continue;
		for (j = 3; j < i; j+=2) {
			if (!is_prime(j)) continue;
			if ((i - j) & 1) continue;
			if (!is_square((i - j) >> 1)) continue;
			break;
		}

		if (j >= i) {
			printf ("\n%d\n", i);
			break;
		}
	}
	return 0;
}
