#include <stdio.h>
#include <stdlib.h>

int main1021(){
	char str[1000];
	int count[10] = {0};
	scanf("%s",str);
	for(int i = 0; i < strlen(str); i++){
		count[str[i]-'0']++;
	}
	for(int i=0;i<10;i++){
		if(count[i] != 0){
			printf("%d:%d\n",i,count[i]);
		}
	}
} 
