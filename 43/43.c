/*
 * Problem 43
 *
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
 *
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
 *
 *     d2d3d4  = 406 is divisible by 2
 *     d3d4d5  = 063 is divisible by 3
 *     d4d5d6  = 635 is divisible by 5
 *     d5d6d7  = 357 is divisible by 7
 *     d6d7d8  = 572 is divisible by 11
 *     d7d8d9  = 728 is divisible by 13
 *     d8d9d10 = 289 is divisible by 17
 *
 *     Find the sum of all 0 to 9 pandigital numbers with this property.
 *
 * Approach :
 * Use lexico permutation generator for 0..9 and for each string, atoi from reqd position, divide by the reqd power of 10 and check against the primes.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int limit;
char *permute;

/* Helper function : reverse a string. Used by get_next_permute() */
char *strrev (char *str) {
	char *start, *end, temp;

	start = str; end = str + strlen(str) - 1;

	while (end >= start) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++; end--;
	}

	return str;
}


/* Permutation Generator : generates in-place permutations, lexicographically. */
char *get_next_permute () {
	static int init = 1;
	int k, l, temp;;

	if (init) {
		permute = (char *) malloc (limit + 1);
		permute[limit] = '\0';

		for (temp = 0; temp < limit; temp++)
			permute[temp] = temp + '0';

		init = 0;
		return permute;
	}
	
	for (k = limit - 2; k >= 0; k--)
		if (permute[k] < permute[k+1])
			break;

	if (k == -1) return NULL;

	for (l = limit - 1; l > k; l--)
		if (permute[l] > permute[k])
			break;

	temp = permute[k];
	permute[k] = permute[l];
	permute[l] = temp;

	strrev(&permute[k+1]);

	return permute;
}

int main () {
	char *num_string;
	unsigned long long sum = 0, number;

	limit = 10;

	while (num_string = get_next_permute()) {
		if (num_string[0] == '0') continue;
		number = atoll(num_string);
		if (((number / 1)       % 1000) % 17) continue;
		if (((number / 10)      % 1000) % 13) continue;
		if (((number / 100)     % 1000) % 11) continue;
		if (((number / 1000)    % 1000) % 7)  continue;
		if (((number / 10000)   % 1000) % 5)  continue;
		if (((number / 100000)  % 1000) % 3)  continue;
		if (((number / 1000000) % 1000) % 2)  continue;
		sum += number;
	}

	printf ("%llu\n", sum);
	return 0;
}
