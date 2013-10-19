#include <stdio.h>
#include <string.h>

/* #define LIMIT 1000000 */

#define DBG() printf ("i:%d\t, j:%d\t, k:%d\t, l:%d\t, err:%d\t, len:%d\n", i, j, k, l, err, len)

int main (int argc, char **argv) {
	int digitss[10], digits[10], len, i, j, k, l, err;
	char number[10], multiple[10];

	int LIMIT = atoi (argv[1]), numx = atoi (argv[2]);

	for (i = 1; i < LIMIT; i++) {

		for (k = 0; k < 10; k++) digits[k] = k;

		sprintf (number, "%d", i);

		len = strlen (number);

		for (l = 0; !err && l < len; l++)
			if (digits[number[l] - '0'] != -1)
				digits[number[l] - '0'] = -1;
			else
				err = -1;

		if (err) { err = 0; continue; }
		if (digits[0] == -1) continue;

		/* printf ("%d\n", i); */

		for (j = 2; j <= numx; j++) {
			
			sprintf (multiple, "%d", i*j);

			if (len != strlen (multiple)) break;

			for (k = 0; k < 10; k++) digitss[k] = k;

			for (l = 0; !err && l < len; l++)
				if (digitss[multiple[l] - '0'] != -1)
					digitss[multiple[l] - '0'] = -1;
				else
					err = -1;

			if (err) { err = 0; break; }
			if (digitss[0] == -1) break;

			for (l = 0; l < len; l++)
				if (digits[multiple[l] - '0'] != -1) {
					/* DBG(); */
					err = -1;
					break;
				}

			if (err) { err = 0; break; }
		}

		if (j > numx) {
			printf ("%d\n%d\n%d\n%d\n%d\n%d\n", i, i*2, i*3, i*4, i*5, i*6);
			/* getchar(); */
			break;
		}
	}

	return 0;
}
