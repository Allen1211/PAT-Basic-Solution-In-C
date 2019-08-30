#include <stdio.h>
#include <stdlib.h>

int func(char *str,char ch){
	int sum = 0;
	int j = 1;
	for(char *p = str; *p != '\0'; p++){
		if(*p == ch){
			sum += j*(ch - '0');
			j *= 10;
		}
	}
	return sum;
}

int main1016(){
	char A[15];
	char B[15];
	char PA,PB;
	scanf("%s %c %s %c",A,&PA,B,&PB);
	printf("%d",func(A,PA) + func(B,PB));
	return 0;
}
