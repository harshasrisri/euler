#include <stdio.h>

int main (int argc, char **argv) {
	unsigned long long frame_size, count = 0, i, j, tiles, max_frame_side, limit = 1000000;

	if (argv[1]) limit = atoi(argv[1]);

	max_frame_side = (limit + 4) / 4;

	for (i = 3; ; i++) {
		for (frame_size = i * 4 - 4, tiles = 0, j = i; ; j++, count++, frame_size += 8)
			if ( tiles + frame_size > limit) break;
			else tiles += frame_size;
		if (j == i) break;
	}

	return printf ("%d\n", count);
}
