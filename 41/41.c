# include <stdio.h>
# include <string.h>

#ifndef LIMIT
#define LIMIT 1000000000 //One Billion
#endif

unsigned char prime[LIMIT/(sizeof(unsigned char) * 8) + 1] = {0};

#define is_prime(x) (!checkbit(x))
#define is_not_prime(x) (checkbit(x))

inline int checkbit (unsigned long long pos) {
	return (prime[pos / (sizeof(prime[0]) * 8)]) & (1 << (pos % (sizeof(prime[0]) * 8)));
}

inline void setbit (unsigned long long pos) {
	(prime[pos / (sizeof(prime[0]) * 8)]) |= (1 << (pos % (sizeof(prime[0]) * 8)));
}

void prepare_primes () {
	unsigned long long i = 2, j, max_check = LIMIT >> 1;

	for (i = 3; i <= max_check; i+=2) {
		if (is_not_prime(i)) continue;
		j = 2;
		/* printf ("%u\n", i); */
		while (i * j < LIMIT) {
			if ((i == 3) && (j & 1)) {
				setbit (j + 1);
				setbit (j - 1);
			}
			setbit(i * j++);
		}
		if (pandigital(i)) printf ("%d\n", i);
	}
}

int pandigital (unsigned long long n) {
	int nums[] = {0,1,2,3,4,5,6,7,8,9};
	int temp;

	if (n < 10) return 1;
	if (n < 100) nums[3] = 0;
	if (n < 1000) nums[4] = 0;
	if (n < 10000) nums[5] = 0;
	if (n < 100000) nums[6] = 0;
	if (n < 1000000) nums[7] = 0;
	if (n < 10000000) nums[8] = 0;
	if (n < 100000000) nums[9] = 0;

	while (n) {
		temp = n % 10;
		n /= 10;
		if (nums[temp]) nums[temp] = 0;
		else return 0;
	}

	return 1;
}

int main () {
	unsigned long long i = LIMIT;

	prepare_primes();

	/* while (--i) { */
	/* 	if (is_not_prime(i)) continue; */
	/* 	printf ("%d\n", i); */
	/* 	if (pandigital(i)) break; */
	/* } */

	/* printf ("%u\n", i); */
	return 0;
}
