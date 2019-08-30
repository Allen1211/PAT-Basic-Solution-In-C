#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main1029(){
	char broken[81],correct[81],wrong[81];
	int M=0;
	scanf("%s %s",correct,wrong);
	for(char *p1=correct,*p2=wrong; *p1 != '\0'; ){
		if(*p1 != *p2){
			int flag = 1;
			for(int i=0;i<M;i++){
				if(broken[i] == toupper(*p1)){
					flag = 0;
					break;
				}
			}
			if(flag){
				broken[M++] = toupper(*p1);
			}
			p1++;
		}else{
			p1++;
			p2++;
		}
	}
	broken[M] = '\0';
	printf("%s",broken);
	return 0;
}
