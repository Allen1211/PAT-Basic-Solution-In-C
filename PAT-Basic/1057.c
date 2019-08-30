#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main1057(){
	int zero=0,one=0,sum=0;
	char ch;
	while((ch=getchar())!='\n'){
		if(isalpha(ch)){
			sum += (int)(tolower(ch) - 'a') + 1;
		}
	}
	int n;
	while(sum){
		n = sum/2;
		if(sum - n*2 == 1){
			one++;
		}else{
			zero++;
		}
		sum = n;
	}
	printf("%d %d",zero,one);
	return 0;
} 
