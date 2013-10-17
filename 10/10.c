/* Frankly, I dont remember what I was thinking when I wrote this program. */ 
/* Now, it simply doesn't like showing to me that it works */

# include <stdio.h>
# include <stdlib.h>

int main (int argc, char **argv) {
	unsigned long *i, *j, *arr, sum = 0, limit;

	if (!argv[1]) {
		fprintf (stderr, "Usage: %s <limit>", argv[0]);
		exit (-1);
	}
   
   limit = atoi(argv[1]);

	arr = (unsigned long*) malloc ((limit >> 3)*sizeof(unsigned long));

	arr[0] = 2;
	arr[1] = 3;

	for (
			i = &arr[2], *i = 0;
			*i < limit && (i - arr) < limit >> 3;
			i++
		) {
		*i = *(i-1) + 2;
		for (j = arr; j < i; *j+=2) {
			if ((*j <= *i >> 1) && !(*i % *j)) {
				*i += 2;
				j = arr;
				continue;
			}
		}
		sum += *i;
	}
	free (arr);
	printf ("%ld\n", sum);
	return 0;
}
