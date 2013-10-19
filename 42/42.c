# include <stdio.h>

int main () {
	int c, i, sum = 0, count = 0, tri[25];

	for (c = 0; c < 25; c++)
		tri[c] = c * (c + 1) / 2;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			for (i = 0; i < 25; i++)
				if (sum == tri[i]) {
					count++;
					break;
				}
			sum = 0;
		} else
			sum += (char)c - 'A' + 1;
	}
	printf ("%d\n", count);
	return 0;
}

