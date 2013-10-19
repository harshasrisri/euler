/*
Problem 32

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#include <stdio.h>
#include <string.h>

int is_pandigital (char *str, int start, int end) {
	int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, i, count = 0;

	if ((start < 0) || (start > 9) || (end < 0) || (end > 9)) return -1;

	if (start > end) {
		start = start ^ end;
		end = start ^ end;
		start = start ^ end;
	}

	for (i = 0; str[i]; i++) {
		if ((digits[str[i] - '0'] < start) || (digits[str[i] - '0'] > end))
			return 0;
		digits[str[i] - '0'] = 'a';
		count++;
	}

	if (end - start + 1 == count ) return 1;

	return 0;
}


int main (int argc, char **argv) {
	int i, j, k, prod, sum = 0, debug = argc - 1;
	char stri[10], strj[10], strp[10], cat[20], all[10000] = {0};

	for (i = 1; i < 100; i++) {
		if (i < 10) j = 1234;
		else j = 123;

		k = 10000 / i + 1;

		for (; j < k; j++) {
			sprintf (stri, "%d", i);
			sprintf (strj, "%d", j);
			sprintf (strp, "%d", prod = i * j);
			sprintf (cat, "%d%d%d", i, j, prod);

			if (strlen(cat) != 9) continue;

			if (!is_pandigital(cat, 1, 9)) continue; 

			if (strstr(all, strp)) continue;

			if (debug) printf ("%4d = %3d x %3d\n", prod, i, j);

			sum += prod;
			strcat (strcat(all, strp), ":");
		}
	}
	printf ("%s\n%d\n", all, sum);
	return 0;
}
