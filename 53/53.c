#include <stdio.h>

int factorial (int num) {
	if (num == 0) return 1;
	else return num * factorial (num - 1);
}

inline int combin (int n, int r) {
	return factorial(n)/factorial(r)/factorial(n-r);
}

int main () {
	int n, r, count = 0;

	for (n = 1; n <= 100; n++)
		for (r = 1; r <= n; r++)
			if (combin(n,r) >= 1000000)
				count++;

	printf ("%d\n", count);
	return 0;
}
