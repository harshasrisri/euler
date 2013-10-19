#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *rotate (char *str) {
	int i = strlen(str) - 1;
	char x = str[i];
	while (i >= 1) {
		str[i] = str[i - 1];
		i--;
		/* printf (" %s\n", str); */
	}
	str[i] = x;
	/* printf (" %s\n", str); */
	return str;
}

int main (int argc, char **argv) {
	int temp, numj, i = atoi(argv[1]);
	char *strj;

	temp = i;
	while ((temp % 10) % 2) temp /= 10;
	if (temp) {
		i+=2;
		return -1;
	}

	printf ("%d", i);
	for (numj = atoi(strj = rotate(argv[1]));
			numj != i; 
			numj = atoi(strj = rotate(strj)))
	{
		printf (" -> %d", numj);
		/* if (is_not_prime(numj)) break; */
		/* setbit(numj); */
	}
	putchar ('\n');
	return 0;
}
