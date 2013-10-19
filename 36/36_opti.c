/* Euler Problem 36 : */

/* The decimal number, 585 = 1001001001 (binary), is palindromic in both bases. */

/* Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2. */

/* (Please note that the palindromic number, in either base, may not include leading zeros.) */

#include <stdio.h>

inline int x_pow_y (int x, int y) {
	int prod = 1;
	while (y--) prod *= x;
	return prod;
}

int is_palin (unsigned int number, int base) {
	unsigned int reversed = 0, temp = number;

	while (temp) {
		reversed = base * reversed + temp % base;
		temp /= base;
	}

	return (number == reversed);
}

int make_bin_palin (int root, int oddlength) {
	int temp = root;
	if (oddlength) root = root >> 1;
	while (root) {
		/* putchar ('*'); */
		temp = (temp << 1) | (root & 1);
		root = root >> 1;
	}
	return temp;
}

int main (int argc, char **argv) {
	unsigned limit, bin_palin = 0, i;
	unsigned long sum = 0;

	if (argv[1]) limit = atoi(argv[1]);
	else limit = 1000000;

	for (i = 1; bin_palin <= limit; i++) {
		if (is_palin ((bin_palin = make_bin_palin (i, 0)), 10)) sum += bin_palin;
		if (is_palin ((bin_palin = make_bin_palin (i, 1)), 10)) sum += bin_palin;
	}

	printf ("%lu\n", sum);
}
