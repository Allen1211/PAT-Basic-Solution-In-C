#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void compress(){
	char str[1001];
	gets(str);
	char pre = str[0];
	int cnt=1;
	for(int i=1;i<strlen(str);i++){
		if(str[i] != pre){
			if(cnt==1){
				printf("%c",pre);
			}else{
				printf("%d%c",cnt,pre);
			}
			cnt = 1;
		}else{
			cnt++;
		}
		pre = str[i];
	}
	if(cnt==1){
		printf("%c",pre);
	}else{
		printf("%d%c",cnt,pre);
	}
}

void decompress(){
	char str[1001];
	gets(str);
	for(int i=0;i<strlen(str);i++){
		if(isdigit(str[i])){
			int n = str[i]-'0';
			while(isdigit(str[++i])){
				n = n*10 + str[i]-'0';
			}
			while(n--) 
				putchar(str[i]);
		}else{
			putchar(str[i]);
		}
	}
}

int main1078(){
	char mode;
	scanf("%c",&mode);
	getchar();
	if(mode == 'C'){
		compress();
	}else{
		decompress();
	}
	printf("\n");
	return 0;
}
