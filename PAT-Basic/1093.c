#include <stdio.h>
#include <stdlib.h>
int main1093(){
	int ASCII[127]={0};
	char ch;
	for(int i=0;i<2;i++){
		while((ch=getchar())!='\n'){
			if(ASCII[ch]==0){
				ASCII[ch] = 1;
				putchar(ch);
			}
		}
	}
	return 0;
}
