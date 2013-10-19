/*
Problem 39

If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <stdio.h>

int main () {
	int m, n, a, b, c, k, mark = 0, maxmark = 0, maxcount = 0;
	unsigned int count[1000] = {0};

	for (m = 1; m < 200; m++) {
		for (n = 1; n < 200; n++) {
			if (m <= n) continue;

			a = (m * m) - (n * n);
			b = 2 * m * n;
			c = (m * m) + (n * n);

			if ((mark = a + b + c) >= 1000) continue;

			printf ("%03d = %3d + %3d + %3d\n", mark, a, b, c);

			count[mark]++;
			if (maxcount < count[mark]) {
				maxcount = count[mark];
				maxmark = mark;
			}
		}
	}

	/* printf ("%d : %d\n", maxmark, max); */
	return 0;
}
