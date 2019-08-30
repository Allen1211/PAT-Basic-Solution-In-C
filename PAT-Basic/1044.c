#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *low[13] = {"tret","jan","feb","mar","apr","may","jun",
				"jly","aug","sep","oct","nov","dec"};
char *high[13] = {"","tam","hel","maa","huh","tou","kes",
				"hei","elo","syy","lok","mer","jou"};

void earth2mars(char *str){
	int n = atoi(str);
	if(n < 13){
		printf("%s",low[n]);
	}else if(n%13 == 0){
		printf("%s",high[n/13]);
	}
	else{
		printf("%s %s",high[n/13],low[n%13]);
	}	
}

void mars2earth(char *str){
	char high_str[5];
	char low_str[5];
	high_str[0] = '\0';
	low_str[0] = '\0';
	int flag = 1,h_count=0,l_count=0,num=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i] == ' '){
			flag = 0;
			continue;
		}
		if(flag)
			high_str[h_count++] = str[i];
		else
			low_str[l_count++] = str[i];
	}
	high_str[h_count] = '\0';
	low_str[l_count] = '\0';
	
	flag = 0;
	for(int i=0;strlen(high_str)&&i<13;i++){
		if(strcmp(high[i],high_str) == 0){
			num += i*13;
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		for(int i=0;strlen(high_str)&&i<13;i++){
			if(strcmp(low[i],high_str) == 0){
				num = i;
				break;
			}
		}		
	}else{
		for(int i=0;strlen(low_str)&&i<13;i++){
			if(strcmp(low[i],low_str) == 0){
				num += i;
				break;
			}
		}	
	}

	printf("%d",num);		
		
}

int main1044(){
	int N;
	scanf("%d",&N);
	char str[10];
	getchar();
	while(N--){
		gets(str);
		if(isdigit(str[0])){
			earth2mars(str);
		}else{
			mars2earth(str);	
		}
		printf("%s",N==0?"":"\n");
	}
	return 0;
}
