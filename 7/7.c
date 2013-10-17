# include <stdio.h>
# include <stdlib.h>

int main (int argc, char **argv) {
	int i = 1, j = 0, length;
	long *array;
	
	if (!argv[1]) {
		fprintf (stderr, "Usage: %s <input>\n", argv[0]);
		exit (-1);
	}

	array = (long *) malloc (sizeof(long) * (length = atoi(argv[1])));
	
	array[0] = 2;
	array[1] = 3;
	
	while (i < length) {
		for (j = 0; j < i; j++) {
			if ((array[j] < array[i] / 2) && !(array[i] % array[j])) {
				array[i] += 2;
				j = 0;
				continue;
			}
		}
		array[++i] = array[i-1] + 2;
	}
	
	printf ("%ld\n", array[length - 1]);
	free (array);
	return 0;
}
