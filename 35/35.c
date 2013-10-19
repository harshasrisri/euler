/* Project Euler Problem - 35 */
/* The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime. */
/* There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97. */
/* How many circular primes are there below one million? */

# include <stdio.h>
# include <string.h>

#ifndef LIMIT
#define LIMIT 1000000 //One Million
#endif

unsigned char prime[LIMIT/(sizeof(unsigned char) * 8) + 1] = {0};

#define is_prime(x) (!checkbit(x))
#define is_not_prime(x) (checkbit(x))

inline int checkbit (unsigned int pos) {
	return (prime[pos / (sizeof(prime[0]) * 8)]) & (1 << (pos % (sizeof(prime[0]) * 8)));
}

inline void setbit (unsigned int pos) {
	(prime[pos / (sizeof(prime[0]) * 8)]) |= (1 << (pos % (sizeof(prime[0]) * 8)));
}

void prepare_primes () {
	int i = 2, j;

	for (i = 3; i <= (LIMIT >> 1); i+=2) {
		if (is_not_prime(i)) continue;
		j = 2;
		while (i * j < LIMIT) {
			if ((i == 3) && (j & 1)) {
				setbit (j + 1);
				setbit (j - 1);
			}
			setbit(i * j++);
		}
	}
}

int rotate (int num) {
	int pow = 1;
	while (pow < num) pow *= 10;
	pow /= 10;
	return (((num % 10) * pow) + (num / 10));
}

int main () {
	int i, j, temp;
	int count = 0;

	prepare_primes();

	for (i = 3; i < LIMIT; i += 2) {
		// check for primality in the sieve
		if (is_not_prime(i)) continue;

		// skip numbers containing an even digit
		temp = i;
		while ((temp % 10) & 1) temp /= 10;
		if (temp) continue;

		for (j = rotate(i); j != i; j = rotate (j))
			if (is_not_prime(j)) break;

		if (j == i) count++;
	}

	printf ("%d\n", ++count); //Finally accounting for 2
	return 0;
}
