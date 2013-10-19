# include <stdio.h>
# include <stdlib.h>

# define FALSE 1
# define TRUE 0

unsigned long long sum_of_primes (unsigned long long size) {
    unsigned long long m, i, sum = 2, maxsum = 0;

    char *seive = (char *)calloc(size, sizeof(char));

	seive[0] = seive[1] = FALSE;
    for (i = 3; i < (size >> 1); i+=2) {
        seive[i+1] = FALSE;

        if (seive[i] == TRUE) {
            sum += i;
			if (sum > size) break;
            for (m = i + 2 * i; m < size; m += 2*i)
                seive[m] = FALSE;
		}
    }

	for (sum -= 2, i = 3; i < size; i+=2) {
		if (seive[i] == TRUE) {
			sum -= i;
			if (sum > size) continue;
			if (seive[sum] == TRUE)
				return sum;
		}
	}
}

int main (int argc, char **argv) {
    return printf ("%llu\n", sum_of_primes (atoll (argv[1])));
}
