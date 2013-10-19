#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;

ull morphdigits (ull num) {
	ull res = 10, keep;
	while (res < num) {
		keep = num % res;
		res *= 10;
		num /= res;
		num = num * res + keep;
		res *= 10;
	}

	return num;
}

int main () {
	ull num = sqrt(19293949596979899), prod, limit = sqrt(10203040506070809);

	for (; num > limit; num--)
		if (morphdigits (prod = num * num) == 10203040506070809)
			break;

	printf ("%llu00 - %llu0\n", prod, num);

	return 0;
}
