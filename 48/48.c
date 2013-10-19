// Last 10 digits of 1^1 + 2^2 + ... + X^X

# include <stdio.h>
# include <stdlib.h>
# define LENGTH 10

int main (int argc, char **argv) {
	unsigned int sum[LENGTH], num[LENGTH], 
				 count = atoi (argv[1]), 
				 i, carry, j, k;

	for (i = 0; i < LENGTH; i++)
		sum[i] = num[i] = 0;

	for (k = 1; k <= count; k++) {
		num[0] = 1;
		for (j = 0; j < k; j++) {
			carry = 0; 
			for (i = 0; i < LENGTH; i++) {
				num[i] = k * num[i] + carry;
				carry = num[i] / 10;
				num[i] %= 10;
			}
		}
		carry = 0;
		for (i = 0; i < LENGTH; i++) {
			sum[i] += num[i] + carry;
			carry = sum[i] / 10;
			sum[i] %= 10;
			num[i] = 0;
		}
	}

	for (i = 1; i <= LENGTH; i++)
		printf ("%d", sum[LENGTH - i]);

	return 0;
}
