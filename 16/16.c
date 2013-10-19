// Sum of Digits of 2^<something>

# include <stdio.h>
# include <stdlib.h>
# define LENGTH (input * 302 / 1000)

int main (int argc, char **argv) {
	unsigned char *num;
	int input = atoi (argv[1]);
	int	i, count, digits = 1, carry = 0, sum = 0;

	num = (char *) calloc ( sizeof (char), LENGTH );
	count = input;

	num[0] = 1;
	while (count--) {
		for (i = 0; i < digits; i++) {
			num[i] = 2 * num[i] + carry;
			carry = num[i] / 10;
			num[i] %= 10;
		}
		if (carry) {
			digits++;
			num[i] = carry;
			carry = 0;
		}
	}
	for (i = LENGTH; i >= 0; i--) {
		if (argv[2]) printf ("%d", num[i]);
		sum += num[i];
	}

	printf ("%d\n", sum);
	return 0;
}
