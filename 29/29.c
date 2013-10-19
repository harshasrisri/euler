# include <stdio.h>
unsigned char distinct[1001][1001] = {0};

int main () {
	int i, j, k, power, dist_nums = 0;

	for (i = 2; i < 1001; i++) {
		power = 2;
		k = i * i;
		while (k < 1001) {
			for (j = i; j < 100/i; j+=power)
				distinct[k][j] = 1;
			power++;
			k *= i;
		}
	}

	for (i = 2; i < 101; i++) {
		for (j = 2; j < 101; j++) {
			printf ("%d ", distinct[i][j]);
			if (!distinct[i][j]) dist_nums++;
		}
		putchar ('\n');
	}

	fprintf (stderr, "%d\n", dist_nums);
	return 0;
}
