#include <stdio.h>
#include <stdlib.h>

int main1072(){
	int N,M,ns=0,nt=0,list[10000]={0};
	char name[5];
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int id;
		scanf("%d",&id);
		list[id] = 1;
	}
	for(int i=0;i<N;i++){
		int k = 0;
		scanf("%s %d",name,&k);
		int flag=0;
		for(int j=0;j<k;j++){
			int id;
			scanf("%d",&id);
			if(list[id] == 1){
				if(flag==0){
					printf("%s:",name);
					flag = 1;
					ns++;
				}
				printf(" %04d",id);
				nt++;
			}
		}
		if(flag) printf("\n");
	}
	printf("%d %d",ns,nt);
	return 0;
}
