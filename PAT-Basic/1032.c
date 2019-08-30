#include <stdio.h>
#include <stdlib.h>


int main1032(){
	int N;
	scanf("%d",&N);
	int *arr = (int*)malloc(sizeof(int)*(N+1));
	memset(arr,0,sizeof(int)*(N+1));
	for(int i=1;i<=N;i++){
		int id,score;
		scanf("%d %d",&id,&score);
		arr[id] += score;
	}
	int max = arr[1];
	int maxi = 1;
	for(int i=1;i<=N;i++){
		if(arr[i] > max){
			max = arr[i];
			maxi = i;
		}
		
	}
	printf("%d %d",maxi,max);
	return 0;
}
