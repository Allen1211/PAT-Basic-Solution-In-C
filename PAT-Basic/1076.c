#include <stdio.h>
#include <stdlib.h>

int main1076(){
	int N;
	scanf("%d",&N);
	while(N--){
		char str[4];
		for(int i=0;i<4;i++){
			scanf("%s",str);
			if(str[2]=='T'){
				printf("%d",str[0]-'A'+1);
			}
		}
	}
	return 0;
}
