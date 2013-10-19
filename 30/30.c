#include <stdio.h>

int dp5_sum (int number) {
	int sum = 0, i;

	while (number) {
		i = number % 10;
		number /= 10;
		sum += i * i * i* i * i;
	}

	return sum;
}

int main () {
	int i, sum = 0;

	for (i = 2; i < 999999; i++)
		if (dp5_sum(i) == i) {
			printf ("%d ", i);
			sum+=i;
		}

	printf ("%d\n", sum);
	return 0;
}
