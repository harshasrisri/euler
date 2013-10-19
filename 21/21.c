# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define LENGTH_DIVIDER 10001
# define START_PARAM (LENGTH_DIVIDER - 1)
# define END_PARAM (LENGTH_DIVIDER - 2)

unsigned long *num, *sum_array, length, not;
unsigned char info = 0, debug = 0, verbose = 0;
unsigned long long sum = 0;

sum_of_factors (void *id) {
	unsigned int i, j;

	for (i = (long) id; i < length; i += not) {
		for (j = 1; j <= i/2+1; j++)
			if (!(i % j)) num[i] += j;
	}
	pthread_exit (NULL);
}

summing_thread (void *id) {
	unsigned int i, j, start, end;
	start = (long)id * START_PARAM + 1;
	end = start + END_PARAM;

	for (i = start; i <= end; i++)
		if (num[i] <= length)
			if ((num[num[i]] == i) && (num[i] != num[num[i]])) {
				sum_array[(long)id] += i;
				if (info) printf ("%d\t%ld\t%ld\n", i, num[i], num[num[i]]);
			}
	pthread_exit (NULL);
}

int main (int argc, char **argv) {
	long i;
	num = (unsigned long *) calloc (length = atoi (argv[1]), sizeof (unsigned long));

	not = length / LENGTH_DIVIDER + 1;

	if (argc > 2) {
		switch (argv[2][0]) {
			case 'i' : info = 1;
					   break;
			case 'd' : debug = 1;
					   break;
			case 'v' : info = debug = 1;
					   break;
			case '1' : case '2' : case '3' : case '4' : case '5' : case '6' : case '7' : case '8' : case '9' : 
					   not = atoi (argv[2]);
					   printf ("%ld\n", not);
					   break;
			default : info = debug = 0;
					  break;
		}
	}

	pthread_t threads[not];
	pthread_attr_t attr;

	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_JOINABLE);
	void *status;

	sum_array = (unsigned long *) calloc (not, sizeof (unsigned long));

	for (i = 0; i < not; i++) {
		if (pthread_create (&threads[i], &attr, sum_of_factors, (void *)i)) {
			fprintf (stderr, "Thread %ld creation failed.\n", i);
			exit (1);
		}
		else if (debug) printf ("Created factorizing thread no %ld\n", i);
	}

	for (i = 0; i < not; i++) {
		if (pthread_join (threads[i], &status)) {
			fprintf (stderr, "Thread %ld join failed.\n", i);
			exit (2);
		}
	}

	for (i = 0; i < not; i++) {
		if (pthread_create (&threads[i], &attr, summing_thread, (void *)i)) {
			fprintf (stderr, "Thread %ld creation failed.\n", i);
			exit (1);
		}
		else if (debug) printf ("Created summing thread no %ld\n", i);
	}

	for (i = 0; i < not; i++) {
		if (pthread_join (threads[i], &status)) {
			fprintf (stderr, "Thread %ld join failed.\n", i);
			exit (2);
		}
	}

	for (i = 0; i < not; i++)
		sum += sum_array[i];

	printf ("%ull\n", sum);
	free (num);
	pthread_exit (NULL);
}
