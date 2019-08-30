#include <stdio.h>
#include <stdlib.h>

int comp1060(int *x,int *y){
	return *x-*y;
}

int main1060(){
	int N;
	scanf("%d",&N);
	int *arr = (int *)malloc(sizeof(int)*(N));
	for(int i=0,dis;i<N;i++){
		scanf("%d",&arr[i]);
	}
	qsort(arr,N,sizeof(int),comp1060);
    int E = 0;
	for(int i=0;i<N;i++){
		if(N-i < arr[i] ){
			E = N-i;
			break;
		}
	}
	printf("%d",E);
	return 0;
}
