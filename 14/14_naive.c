# include <stdio.h>
# include <stdlib.h>

int main (int argc, char **argv) {
	int limit, i = 0, j = 0, k = 0, l = 0, result;

	if (!argv[1]) {
		fprintf (stderr, "Usage: %s <limit>\n", argv[0]);
		exit (-1);
	}

	limit = atoi(argv[1]);

	for (i = limit >> 2; i < limit; i++) {
		j = i;
		k = 0;
		while (j > 1) {
			if (j & 1)
				j += (j<<1) + 1;
			else 
				j = j>>1;
			k++;
		}
		if (k > l) {
			l = k;
			result = i;
		}
	}

	printf ("%d\n", result);
	return 0;
}
