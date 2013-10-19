#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int k, n = 1, sum;

	while (sum < 1001) {
		sum = 0;
		for (k = 2; k <= n; k++) {
			if ((k * n) % (k - 1))
				continue;
			sum++;
		}
		n++;
	}

	printf ("%d\n", n);
	return 0;
}
