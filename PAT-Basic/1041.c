#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu{
	char id[17];
	int check;
	int test;
}Stu;

int main1041(){
	int N,M;
	scanf("%d",&N);
	Stu *arr = (Stu*)malloc(sizeof(struct stu)*N);
	for(int i=0;i<N;i++){
		scanf("%s %d %d",arr[i].id, &(arr[i].check), &(arr[i].test));
	}
	scanf("%d",&M);
	while(M--){
		int target;
		scanf("%d",&target);
		for(int i=0;i<N;i++){
			if(target == arr[i].check){
				printf("%s %d%s",arr[i].id,arr[i].test,M==0?"":"\n");
				break;
			}
		}
	}
	return 0;
}
