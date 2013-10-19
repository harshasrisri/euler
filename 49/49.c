#include <stdio.h>
#include <string.h>

#ifndef LIMIT
#define LIMIT 10000
#endif

unsigned char prime[LIMIT/(sizeof(unsigned char) * 8 * 2) + 1] = {0};

#define is_prime(x) (!checkbit(prime,x))
#define is_not_prime(x) (checkbit(prime,x))

inline int checkbit (unsigned char array[], unsigned int pos) {
	if (pos == 0) return 0;
	if (pos == 1) return 0;
	if (pos == 2) return 0;
	if (!(pos & 1)) return 1;
	pos = pos >> 1;
	return (array[pos / (sizeof(array[0]) * 8)]) & (1 << (pos % (sizeof(array[0]) * 8)));
}

inline void setbit (unsigned char array[], unsigned int pos) {
	if (!(pos & 1)) return;
	pos = pos >> 1;
	(array[pos / (sizeof(array[0]) * 8)]) |= (1 << (pos % (sizeof(array[0]) * 8)));
	return;
}

void prepare_primes () {
	int i = 2, j;

	for (i = 3; i <= (LIMIT >> 1); i+=2) {
		if (is_not_prime(i)) continue;
		j = 2;
		while (i * j < LIMIT) {
			setbit(prime, i * j++);
		}
	}
}

int check_permute (int a, int b, int c) {
	char aa[10], bb[10], cc[10], *temp;
	int i = 0;

	sprintf (aa, "%d", a);
	sprintf (bb, "%d", b);
	sprintf (cc, "%d", c);

	for (i = 0; (aa[i]) && (temp = strchr(bb, aa[i])); i++)
		*temp = 'a';
	if (aa[i]) return 0;

	for (i = 0; (aa[i]) && (temp = strchr(cc, aa[i])); i++)
		*temp = 'a';
	if (aa[i]) return 0;

	return 1;
}

int main () {
	int i, j, k;

	prepare_primes();

	for (i = 1001; i < LIMIT; i+=2) {
		if (is_not_prime(i)) continue;
		for (j = 2; (k = i+j+j) < LIMIT; j+=2) {
			if (is_not_prime(i+j)) continue;
			if (is_not_prime(k)) continue;
			if (check_permute (i, i+j, k))
				printf ("%d, %d, %d\n", i, i+j, k);
		}
	}
	return 0;
}
