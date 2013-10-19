# include <stdio.h>

int main () {
	int days = 2, yr, mnt, count = 0;
	int dom[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	for (yr = 1901; yr <= 2000; yr++) {
		for (mnt = 0; mnt < 12; mnt++) {
			if (mnt == 1) {
				if (!(yr % 4)) dom[1] = 29;
				if (!(yr % 100)) dom[1] = 28;
				if (!(yr % 400)) dom[1] = 29;
			}
			days += dom[mnt];
			days %= 7;
			if (days == 6) count++;
		}
	}
	printf ("%d\n", count);
	return 0;
}