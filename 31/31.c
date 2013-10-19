# include <stdio.h>

/* int main () { */
/* 	int p1, p2, p5, p10, p20, p50, p100, count = 0; */

/* 	for (p1 = 0; p1 <= 200; p1++) { */
/* 		for (p2 = 0; p2 <= 100; p2++) { */
/* 			for (p5 = 0; p5 <= 40; p5++) { */
/* 				for (p10 = 0; p10 <= 20; p10++) { */
/* 					for (p20 = 0; p20 <= 10; p20++) { */
/* 						for (p50 = 0; p50 <= 4; p50++) { */
/* 							for (p100 = 0; p100 <= 2; p100++) { */
/* 								if (p1 + p2*2 + p5*5 + p10*10 + p20*20 + p50*50 + p100*100 == 200) */
/* 									count++; */
/* 							} */
/* 						} */
/* 					} */
/* 				} */
/* 			} */
/* 		} */
/* 	} */

/* 	printf ("%d\n", count); */

/* 	return 0; */
/* } */

int main (int argc, char **argv) {
	int a, b, c, d, e, f, g, m = atoi(argv[1]), count = 0;

	for( a=m ; a>=0 ; a -= 200 ) 
		for( b=a ; b>=0 ; b -= 100 ) 
			for( c=b ; c>=0 ; c -= 50 ) 
				for( d=c ; d>=0 ; d -= 20 ) 
					for( e=d ; e>=0 ; e -= 10 ) 
						for( f=e ; f>=0 ; f -= 5 ) 
							for( g=f ; g>=0 ; g -= 2 ) 
								count++; 

	return printf("%d\n", count);
}
