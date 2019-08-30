#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main1069(){
	int M,N,S,win_count=0;
	char temp[21];
	scanf("%d %d %d",&M,&N,&S);
	getchar();
	if(S > M){
		printf("Keep going...");
		return 0;
	}	
	char winner[M/N+1][21];
	int count=1;
	for(int i=0;i<M;i++){
		if(win_count==0){
			for(int j=0;j<S;j++){
				scanf("%s",temp);
			} 
			strcpy(winner[win_count++],temp);
			printf("%s",temp);
			i = S-1;
			continue;
		}
		scanf("%s",temp);
		if(count%N==0){
			int flag = 1;
			for(int j=0;j<win_count&&i<M;j++){
				if(strcmp(winner[j],temp)==0){
					flag = 0;
					break;
				}
			}
			if(flag){
				strcpy(winner[win_count++],temp);
				printf("\n%s",temp);
				count = 1;
			}
		}else{
			count++;
		}
	}
	return 0;
}
