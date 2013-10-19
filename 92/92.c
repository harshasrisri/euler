/* Project Euler Problem - 92 */

/* A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before. */

/* For example, */

/* 	44 → 32 → 13 → 10 → 1 → 1 */
/* 	85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89 */

/* 	Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89. */

/* 	How many starting numbers below ten million will arrive at 89? */

#include<stdio.h>

#define LIMIT 10000000

int main (int argc, char **argv) {
	int i, n, temp = 0, count = 0;

	for (i = 1; i < LIMIT; i++) {
		if (argv[1]) printf ("%d", i);
		temp = n = i;
		while (1) {
			if ((temp == 1) || (temp == 89)) break;
			temp = 0;
			while (n) {
				temp += (n % 10) * (n % 10);
				n /= 10;
			}
			if (argv[1]) printf (" -> %d", temp);
			n = temp;
		}
		if (temp == 89) count++;
		if (argv[1]) putchar ('\n');
	}

	printf ("%d\n", count);
	return 0;
}
