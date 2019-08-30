#include <stdio.h>
#include <stdlib.h>

int comp1045(int *x,int *y){
	return *x-*y;
}

int main1045(){
	int N;
	scanf("%d",&N);
	int *arr = (int*)malloc(sizeof(int)*N);
	int *mark = (int*)malloc(sizeof(int)*N);
	int *result = (int*)malloc(sizeof(int)*N);
	int max = 0;
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		mark[i] = (i==0 || arr[i] > max);
		if(arr[i] > max) max = arr[i];			
	}
	
	int min = 2000000000;
	int count = 0;
	for(int i=N-1;i>=0;i--){
		if(mark[i] && arr[i] < min){
			result[count++] = arr[i];
		}
		if(arr[i] < min) min = arr[i];
	}
	qsort(result,count,sizeof(int),comp1045);
	printf("%d%s",count,count==0?"\n\n":"\n");
	for(int i=0;i<count;i++){
		printf("%d%s",result[i],i==count-1?"":" ");
	}
	return 0;
}
