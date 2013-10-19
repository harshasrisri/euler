#include <stdio.h>

int main () {
	long double pyr[37] = {'0'};
	long double cub[37] = {'0'};
	int a,b,c,d,e,f,g,h,i;
	long double tot = 0, totp = 0, totc = 0;

	for (a = 1; a <= 4; a++)
		for (b = 1; b <= 4; b++)
			for (c = 1; c <= 4; c++)
				for (d = 1; d <= 4; d++)
					for (e = 1; e <= 4; e++)
						for (f = 1; f <= 4; f++)
							for (g = 1; g <= 4; g++)
								for (h = 1; h <= 4; h++)
									for (i = 1; i <= 4; i++) {
										pyr[a+b+c+d+e+f+g+h+i]++;
										totp++;
									}

	for (a = 1; a <= 6; a++)
		for (b = 1; b <= 6; b++)
			for (c = 1; c <= 6; c++)
				for (d = 1; d <= 6; d++)
					for (e = 1; e <= 6; e++)
						for (f = 1; f <= 6; f++) {
							cub[a+b+c+d+e+f]++;
							totc++;
						}

	printf ("%g\t%g\n", (double) totp, (double) totc);
	for (i = 1; i <= 36; i++) {
		printf ("%g\t%g\t", (double) pyr[i], (double) cub[i]);
		pyr[i] /= totp;
		cub[i] /= totc;
		printf ("%g\t%g\n", (double) pyr[i], (double) cub[i]);
	}

	for (a = 1; a <= 36; a++)
		for (b = 1; b <= 36; b++)
			if (pyr[a] > cub[b])
				tot += pyr[a] * cub[b];

	printf ("%1.9g\n", (double) tot);
	return 0;
}
