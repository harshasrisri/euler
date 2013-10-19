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

/* int is_palin (int number, int base) { */
/* 	int temp = number, nod = 0, mid, i, left, right; */

/* 	while ((temp /= base)) nod++; */

/* 	mid = (nod & 1) ? (nod + 1) / 2 : nod / 2; */

/* 	for (i = 0; i < mid; i++) { */
/* 		left = (number / x_pow_y (base, (nod - i))) % base; */
/* 		right = (number % x_pow_y (base, (i + 1))) / x_pow_y (base, i); */
/* 		if (left != right) return 0; */
/* 	} */
	
/* 	return 1; */
/* } */

int is_palin (unsigned int number, int base) {
	unsigned int reversed = 0, temp = number;

	while (temp) {
		reversed = base * reversed + temp % base;
		temp /= base;
	}

	return (number == reversed);
}

int main () {
	unsigned int i;
	unsigned long sum = 0, nod = 1;
	for (i = 1; i < 1000000; i+=2)
		if (is_palin (i, 10) && is_palin (i, 2)) {
			/* fprintf (stderr, "%7d : %31b", i, i); */
			fprintf (stderr, "%7d\n", i);
			sum += i;
		}

	printf ("%lu\n", sum);
}
