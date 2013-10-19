# include <stdio.h>
int main () {
	long sum = 0, limit = 3;
	while (limit <= 1001) {sum += (4 * limit * limit) - (6 * limit) + 6; limit += 2;}
	printf ("%ld\n", ++sum);
	return 0;
}
