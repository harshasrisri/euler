#include<stdio.h>

int main () {
	int i, sum = 0;

	for (i = 1; i < 1000; i++)
		if (!(i % 3)) sum += i;
		else if (!(i % 5)) sum += i;

	return printf ("%d\n", sum);
}
