# include <stdio.h>

int main () {
	int a = 0, b = 0, c = 0, f = 0;

	for (c = 500; c > 0; c--) {
		for (a = 500; a > 0; a--) {
			for (b = 1; b < 500; b++) {
				if ((a*a + b*b) == (c*c)) {
					if (a + b + c == 1000) {
						f = 1;
					}
				}
				if (f) break;
			}
			if (f) break;
		}
		if (f) break;
	}
	printf ("(%d) - %d*%d*%d = %d\n", (a+b+c), a, b, c, a*b*c);
}
