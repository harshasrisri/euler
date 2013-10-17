# include <stdio.h>

int main () {
	unsigned long fibo[] = {1,2,3}, sum = 2.0;
	
	while (fibo[2] <= 4000000) {
		fibo[0] = fibo[1];
		fibo[1] = fibo[2];
		fibo[2] = fibo[0] + fibo[1];
		if (!(fibo[2] % 2)) printf ("3. %d - %d\n", fibo[2], sum += fibo[2]);
	}
	
	printf ("%d\n", sum);
}
