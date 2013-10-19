#include <stdio.h>
int main () {
	int i;
	unsigned long long prod = 28433;
	for (i = 1; i <= 7830457; i++) {
		prod <<= 1;
		prod %= 10000000000;
	}
	printf ("%llu\n", prod+1);
	return 0;
}
