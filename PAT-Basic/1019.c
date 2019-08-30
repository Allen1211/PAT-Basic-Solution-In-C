#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char input[5];
char down[5];
char up[5];

int comp(char *a, char *b){
	return *a - *b;
}
int compdesc(char *a,char *b){
	return -comp(a,b);
}
		
int main1019(){
	int n;
	scanf("%d",&n);
	sprintf(input,"%04d",n);
	while(1){
		memcpy(down,input,5);
		memcpy(up,input,5);
		qsort(down,4,sizeof(char),compdesc);
		qsort(up,4,sizeof(char),comp);
		int a = atoi(down);
		int b = atoi(up);
		int result = a - b;	
		if(result == 6174 || result == 0){
			printf("%04d - %04d = %04d",a,b,result);
			break;
		}else{
			printf("%04d - %04d = %04d\n",a,b,result);	
		}
		sprintf(input,"%04d",result);
	}
	return 0;
}
