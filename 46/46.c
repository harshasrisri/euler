# include <stdio.h>
# include <string.h>

#ifndef LIMIT
#define LIMIT 10000000000
#endif

#ifndef LIMIT1
#define LIMIT1 10000000000
#endif

unsigned char prime[LIMIT/(sizeof(unsigned char) * 8 * 2) + 1] = {0};
unsigned char goldbach[LIMIT1/(sizeof(unsigned char) * 8 * 2) + 1] = {0};

#define is_prime(x) (!checkbit(prime,x))
#define is_not_prime(x) (checkbit(prime,x))
#define is_not_goldbach(x) (checkbit(goldbach,x))

inline int checkbit (unsigned char array[], unsigned int pos) {
	if (pos == 2) return 0;
	if (!(pos & 1)) return 1;
	return (array[pos / (sizeof(array[0]) * 8)]) & (1 << (pos % (sizeof(array[0]) * 8)));
}

inline void setbit (unsigned char array[], unsigned int pos) {
	if (!(pos & 1)) return;
	pos = pos >> 1;
	(array[pos / (sizeof(array[0]) * 8)]) |= (1 << (pos % (sizeof(array[0]) * 8)));
	return;
}

void prepare_primes () {
	unsigned long int i = 2, j, temp;
	unsigned long long temp1;

	for (i = 3; i <= (LIMIT >> 1); i+=2) {
		if (is_not_prime(i)) continue;
		j = 2;
		setbit(goldbach, i);
		while ((temp = i * j) < LIMIT) {
			if ((temp1 = i + 2 * (j - 1) * (j - 1)) < LIMIT1) {
				setbit (goldbach, temp1);
			}
			if ((i == 3) && (j & 1)) {
				setbit (prime, j + 1);
				setbit (prime, j - 1);
				setbit (goldbach, j + 1);
				setbit (goldbach, j - 1);
			}
			setbit(prime, temp);
			setbit(goldbach, temp);
			j++;
		}
	}
}

int main () {
	int i = 3;

	prepare_primes();

	while (is_not_goldbach(i)) 
		printf ("%d\n", i+=2);

	printf ("%d\n", i);
	return 0;
}
