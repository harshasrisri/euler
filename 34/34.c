#include <stdio.h>

/* int factorial (int n) { */
/* 	if ((n == 0) || (n == 1) || (n == 2)) return n; */
/* 	return n * factorial(n - 1); */
/* } */

int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int digit_fact_sum (unsigned long n) {
	unsigned long temp, sum = 0;

	while (n) {
		temp = n % 10;
		n /= 10;
		sum += factorial[temp];
	}

	return sum;
}

int main (int argc, char **argv) {
	unsigned long i, limit = 100000, sum = 0;

	if (argv[1]) limit = atoi(argv[1]);

	for (i = 3; i < limit; i++)
		if (i == digit_fact_sum(i))
			printf ("%d : %d\n", i, sum += i);

	return 0;
}
