# include <stdio.h>

int check_permute (char *argv) {
	char *temp, *save;
	save = argv;

	while (*save) {
		temp = save;
		while (*++temp)
			if (*temp == *save)
				return 0;
		save++;
	}

	return 1;
}

int main () {
	unsigned long i, count = 0;
	char buf[11];

	for (i = 123456789; i <= 9876543210; i++) {
		sprintf (buf, "%010ld", i);
		if (check_permute (buf)) count++;
		if (count == 1000000) {
			printf ("%10ld", i);
			return 0;
		}
	}
}
