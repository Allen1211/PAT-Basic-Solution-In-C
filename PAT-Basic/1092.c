#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main1092(){
	int N,M,cake[1001]={0},sale,max=0;
	scanf("%d %d",&N,&M);
	while(M--){
		for(int i=1;i<=N;i++){
			scanf("%d",&sale);
			cake[i]+=sale;
			if(cake[i] > max) max = cake[i];
		}
	}
	printf("%d\n",max);
	int cnt = 0;
	for(int i=1;i<=N;i++){
		if(cake[i]==max){
			printf("%s%d",cnt==0?"":" ",i);
			cnt++;
		}
	}
	return 0;
}
