#include <stdio.h>

int N[1000001], L[20];
int main (int argc, char **argv) {
	unsigned long long cnt, frame_size, count = 0, i, j, tiles, max_frame_side, limit = 1000000;

	if (argv[1]) limit = atoi(argv[1]);

	max_frame_side = (limit + 4) / 4;

	for (i = 3; ; i++) {
		for (frame_size = i * 4 - 4, tiles = 0, j = i; ; j++, count++, frame_size += 8) {
			if ( tiles + frame_size > limit) break;
			tiles += frame_size;
			N[tiles]++;
		}
		if (j == i) break;
	}

	for (cnt = 0, i = 0; i < 1000001; i++) {
		printf ("%d\n", N[i]);
		if (N[i] <= 10)
			L[N[i]]++;
	}

	for (i = 0; i < 11; i++)
		cnt += L[i];

	/* return printf ("%d\t%d\n", count, cnt); */
}
