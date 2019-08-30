#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main1081(){
	int N;
	char pwd[100];
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		gets(pwd);
		if(strlen(pwd) < 6){
			printf("Your password is tai duan le.");
			if(i != N-1) printf("\n");
			continue;
		}
		int flag =1 ;
		int has_digit = 0;
		int has_alpha = 0;
		for(int j=0;j<strlen(pwd);j++){
			int is_digit = isdigit(pwd[j]);
			int is_alpha = isalpha(pwd[j]);
			if(is_digit || is_alpha || pwd[j]=='.'){
				if(!has_digit && is_digit) has_digit = is_digit;
				if(!has_alpha && is_alpha) has_alpha = is_alpha;	
			}else{
				printf("Your password is tai luan le.");
				flag = 0;
				break;
			}
		}
		if(flag){
			if(!has_digit){
				printf("Your password needs shu zi.");
			}else if(!has_alpha){
				printf("Your password needs zi mu.");
			}else{
				printf("Your password is wan mei.");
			}
		}
		if(i != N-1) printf("\n");
	}
	return 0;
}
