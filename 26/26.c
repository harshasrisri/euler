# include <stdio.h>

inline int is_there (int num, int array[], int count) {
	while (count)
		if (num == array[--count]) return 0;
	return 1;
}

int main () {
	int i, rems[10000] = {0}, rem = 1, count, maxx = 0, max = 0;

	for (i = 1; i < 1000; i++) {
		rem = 1;
		count = 0;
		do {
			rems[count++] = rem;
			rem = (10 * rem) % i;
			if (!rem) break;
			if (count > 9999) break;
		} while (is_there (rem, rems, count));
		if (max < count) {
			max = count;
			maxx = i;
		}
	}
		printf ("%d\n", maxx);

	return 0;
}
