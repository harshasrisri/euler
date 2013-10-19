#include <stdio.h>

typedef unsigned long long ull;

ull reverse (ull num) {
	ull rev = 0;
	while (num) {
		rev *= 10;
		rev += num % 10;
		num /= 10;
	}
	return rev;
}

int main () {
	 ull count = 0, i, j, sum, rev;

	 for (i = 1; i <= 10000; i++) {
		 sum = i;
		 rev = reverse (sum);
		 for (j = 0; j < 50; j++) {
			 sum += rev;
			 if (sum == (rev = reverse(sum)))
				 break;
		 }

		 if (j == 50)
			 count++;
	 }

	 printf ("%llu\n", count);
}
