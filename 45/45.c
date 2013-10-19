# include <stdio.h>
# include <stdlib.h>

int main (int argc, char **argv) {
	unsigned long limit = atoi(argv[1]), pent, hex, n1, n2, flag = 1;

	printf ("test: %ld\n", limit * (2 * limit -1));
	for (n1 = 27695; n1 < limit && flag; n1++) {
		for (n2 = 0; n2 < 2*n1 && flag; n2++) {
				pent = n2 * (3 * n2 - 1) / 2;
				hex = n1 * (2 * n1 - 1);
				if (pent == hex)
					flag = 0;
		}
	}
	if (!flag) printf ("result: % ld - %ld\n", n1, hex);
	return 0;
}
					
