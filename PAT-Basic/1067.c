#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main1067(){
	char pwd[21];
	char input[10000];
	int N,count=0;
	scanf("%s %d",pwd,&N);
	getchar();
	while(count < N){
		gets(input);
		if(strlen(input) == 1 && input[0]=='#'){
			break;
		} 
		else if(strcmp(input,pwd) == 0){
			printf("%sWelcome in",count==0?"":"\n");
			break;
		}else{
			printf("%sWrong password: %s",count==0?"":"\n",input);
			count++;
		}
		if(count >= N){
			printf("\nAccount locked");
			break;
		}
	}
	return 0;
}

