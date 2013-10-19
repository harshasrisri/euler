#include <stdio.h>

unsigned int nums[10000000];

int main () {
	int count = 0, i, j, curr_factors = 0, prev_factors = 1;

	for (i = 1; i < 10000000; i++)
		for (j = 1; j * i < 10000000; j++)
			nums[i*j]++;

	for (i = 1; i < 10000000; i++)
		if (nums[i] == nums[i+1])
			count++;

	printf ("%d\n", count);
}
