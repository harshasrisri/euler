# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

# define BIG_LEN (add_num->big_len)
# define SMALL_LEN (add_num->small_len)
# define BIGGER (add_num->bigger)
# define SMALLER (add_num->smaller)

struct big_num_str {
	char *bigger;
	char *smaller;
	unsigned int big_len;
	unsigned int small_len;
};

int is_valid (char *s) {
	while (*s)
		if (!isdigit(*s)) return 0;
		else s++;
	return 1;
}

void stradd (struct big_num_str *add_num) {
	int temp = 0;
	char end_flag = 0, *bigger = BIGGER, *smaller = SMALLER, *a, *b;

	smaller += SMALL_LEN - 1;
	bigger += BIG_LEN - 1;

	while (bigger >= BIGGER) {
		if (!(*bigger - '0') && !(*smaller - '0')) {
			a = bigger; b = smaller;
			while (!(*a - '0') && !(*b - '0')) {
				if ((a >= BIGGER) || (b >= SMALLER)) {
					end_flag = 1;
					break;
				}
				a--; b--;
			}
			if (end_flag) {
				*smaller = temp + '0';
				return;
			}
		}
		temp += *bigger-- - '0';
		if (smaller >= SMALLER)
			temp += *smaller - '0';
		*smaller-- = (temp % 10) + '0';
		temp /= 10;
	}
}

int main (int argc, char **argv) {
	struct big_num_str *add_num;
	int count = 0;
	char *c, *temp;
	
	add_num = (struct big_num_str *) malloc (sizeof (struct big_num_str));

	BIGGER = (char *) malloc (1001);
	SMALLER = (char *) malloc (1001);
	
	for (count = 0; count < 1000; count++)
		BIGGER[count] = SMALLER[count] = '0';

	count = 0;
	BIGGER[1000] = SMALLER[1000] = '\0';
	BIGGER[999] = SMALLER[999] = '1';
	c = SMALLER;

	//while (*c == '0') {
		stradd(add_num);
		temp = SMALLER;
		SMALLER = BIGGER;
		BIGGER = temp;
		count++;
	//}

	printf ("%d - %s\n", count, BIGGER);
	return 0;
}
