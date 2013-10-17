# include <stdio.h>

int main (int argc, char **argv) {
	unsigned long long num = atoll (argv[1]), i;

	while (!(num & 1)) num >>= 1;

	for (i = 1; i < num; i+=2) {
		if (!(i % 3) || !(i % 5)) continue;
		while (!(num % i))
			num /= i;
	}

	printf ("%llu\n", num);
	return 0;
}
