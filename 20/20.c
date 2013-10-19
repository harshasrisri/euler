// Sum of Digits of 100!

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define LENGTH 500


int main (int argc, char **argv) {
	unsigned char num[LENGTH] = {' '};
	int	i, j, count = atoi (argv[1]), digits = 1, carry = 0, sum = 0;

	num[0] = 1;
	for (j = 1; j <= count; j++) {
		printf ("%3d : ", j);
		for (i = 0; i < digits; i++) {
			num[i] = j * num[i] + carry;
			carry = num[i] / 10;
			num[i] %= 10;
			printf ("%d", num[i]);
		}
		while (carry) {
			digits++;
			num[i] = carry % 10;
			printf ("%d", num[i]);
			carry /= 10;
			i++;
		}
		printf ("   %d\n", carry);
//		if (!(count % 10)) {
//			i = 0;
//			while (!num[i]) i++;
//			memmove ((void *)num[0], (void *)num[i], digits-=i) ;
//			memset ((void *) num[digits], 0, LENGTH-digits);
//		}
	}
	for (i = 0; i < LENGTH; i++)
		sum += num[i];

	printf ("%d\n", sum);
	return 0;
}
