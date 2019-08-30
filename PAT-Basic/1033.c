#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main1033(){
	char broken[100];
	int ASCII[128] ={0};
	char text[100001];
	gets(broken);
	gets(text);
	int upper_broken = 0;
	for(int i=0;i<strlen(broken);i++){
		int index = (int)broken[i];
		ASCII[index] = 1;
	}
	upper_broken = ASCII['+'];
	int len = strlen(text);
	int flag = 1;
	for(int i=0; i<len;i++){
		char ch = text[i];
		if( upper_broken&&isupper(ch)){
			continue;
		}
		if(!ASCII[toupper(ch)]){
			putchar(ch);
			flag = 0;
		}
	}
	if(flag){
		printf("");
	}
	return 0;
	
}
