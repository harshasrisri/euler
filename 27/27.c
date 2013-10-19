#include <stdio.h>
#include <stdlib.h>

#ifndef LIMIT
#define LIMIT 1000
#endif

# define my_sqrt(x) sqr_lim = x; _my_sqrt(0,x);
# define PRIME 0
# define NOT_PRIME 1

typedef long long ull;
ull sqr_lim;

ull _my_sqrt (ull low, ull high) {
	ull mid = 0, prod = 0, ret = 0;
	mid = (low + high);
	mid = (mid % 2)	? (mid/2)+1 : (mid/2);
	prod = mid * mid;

#if debug
	printf ("%ld\t%ld\t%ld\t%ld\n", low, high, mid, prod);
#endif

	if (mid == low) 
		return mid + 1;
	if ((mid == high) || (prod == sqr_lim))
		return mid;
	else if (prod > sqr_lim)
		ret = _my_sqrt (low, mid);
	else 
		ret = _my_sqrt (mid, high);
	return ret;
}

char *seive;

void gen_primes (ull limit) {
	ull m, i, sum = 0, crosslimit = my_sqrt(limit);

	seive = (char *)calloc(limit, sizeof(char));

	for (i = 3; i < crosslimit; i+=2) {
		seive[i+1] = NOT_PRIME;
		if (seive[i] == PRIME) {
			for (m = i*i; m < limit; m+=2*i) {
				seive[m] = NOT_PRIME;
			}
		}
	}

	return;
}

int main () {
	int i, j, a, b, n;
	int a_max, b_max, n_max;

	gen_primes (LIMIT * LIMIT);

	for (i = LIMIT; i >= 0; i--) {
		if (seive[i] == PRIME) b = i;
		else continue;

		for (j = LIMIT; j >= -LIMIT; j--) {
			if (1 + j + b < 0) continue;
			if (seive[1 + j + b] == PRIME) a = j;
			else continue;

			for (n = 0;
					(n * n + a * n + b) > 0 && seive[n * n + a * n + b] == PRIME;
					n++)
				;

			if (n_max < n) {
				a_max = a;
				b_max = b;
				n_max = n;
			}
		}
	}

	printf ("a : %d, b : %d, a * b : %d\n", a_max, b_max, a_max*b_max);
	return 0;
}
