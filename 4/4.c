# include <stdio.h>

int main () {
	int i, j, f = 0;
	
	for (i = 998001; i > 99999; i--) {
		if ((i/100000) == (i%10))
			if (((i/10000)%10) == ((i%100)/10))
				if (((i/1000)%10) == ((i%1000)/100))
					for (j = 999; j > 333; j--) {
						if (!(i % j)) {
							f = 1;
							break;
						}
					}
		if (f && (i / j < 999))
			break;
	}
	
	printf ("%d * %d = %d\n", j, i/j, i);
}