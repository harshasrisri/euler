# include <stdio.h>
# include <string.h>

int main () {
	unsigned char num1[1001]={{0}}, num2[1001]={{0}}, num3[1001]={{0}}, *a=num1, *b=num2, *c=num3, *t, carry=0;
	unsigned int index=2, i, len;

	num1[0] = '1';
	num2[0] = '1';

	while (!c[999]) {
		len = strlen (b);
		for (i = 0; i < len; i++) {
			c[i] = b[i] - '0' + carry;
			if (a[i] >= '0') c[i] += a[i] - '0';
			carry = c[i] / 10;
			c[i] %= 10;
			c[i] += '0';
			printf ("%d ", carry);
		}
		if (carry) c[i] = carry + '0';
		printf ("\n== %d ==\na: %s\nb: %s\nc: %s\n", index, a, b, c);
		t = a;
		a = b;
		b = c;
		c = t;
		index++;
	}
	return 0;
}
