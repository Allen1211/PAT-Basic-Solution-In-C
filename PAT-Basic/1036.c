#include <stdio.h>
#include <stdlib.h>
int main1036(){
	int N;
	char ch;
	scanf("%d %c",&N,&ch);
	int w = N;
	int h = (int)(N/2.0 + 0.5);
	for(int i=1;i<=h;i++){
		putchar(ch);
		for(int j=2;j<w;j++){
			printf("%c",i==1||i==h?ch:' ');
		}
		putchar(ch);
		printf("%s",i==h?"":"\n");
	}
	return 0;
}
