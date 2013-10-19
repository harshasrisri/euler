# include <stdio.h>

unsigned long long i,r,n,m,sum = 0,m = 10000000000;

main () {
	for (n=1;n<=1000;n++)
	{
		r=n;
		for(i=2;i<=n;i++)
			r=(r*n)%m;
		sum+=r;
	}
	printf("%llu\n",sum % m);
}
