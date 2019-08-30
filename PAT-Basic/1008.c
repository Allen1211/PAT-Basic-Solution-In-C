#include <stdio.h>
#include <stdlib.h>

int main1008(){
	int N,M;
	scanf("%d %d",&N,&M);
	M = M%N;
	int* arr = malloc(sizeof(int)*(N + N - M));
	for(int i=0;i<N;i++){
		scanf("%d",arr+i);	
	}
	for(int i = 0; i < N-M; i++){
		arr[N+i] = arr[i];
	}
	for(int i = N-M; i < N+N-M; i++){
		printf("%s%d",i==N-M?"":" ",arr[i]);
	}
	return 0;
}
