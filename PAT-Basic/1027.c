#include <stdio.h>
void print1027(int i, int j,char c){
	for (int k = (i - j) / 2; k > 0; k--) {
		putchar(' ');
	}
	for (int k = j; k > 0; k--) {
		putchar(c);
	}
	putchar('\n');
}
int main1027()
{
	int N,i,n;
	char c;
	scanf("%d %c", &N,&c);
	for (i = 1,n = 0; ; ) {
		if (i == 1) 
			n = 1;
		else
			n += i * 2;
		if (n>N-2*(i+2))
			break;
		i += 2;
	}
	for (int j = i; j >= 1; j -= 2) {
		print1027(i, j, c);	
	}
	for (int j = 3; j <= i; j += 2) {
		print1027(i, j, c);
	}
	printf("%d", N-n);
	return 0;
}
