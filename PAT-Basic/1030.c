#include <stdio.h>
#include <stdlib.h>

int comp1030(int *a,int *b){
	return *a - *b;
}

int main1030(){
	int N;
	long int p;
	scanf("%d %ld",&N,&p);
	int *arr = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++){
		scanf("%d",arr+i);
	}
	qsort(arr,N,sizeof(int),comp1030);
	int result = 0;
	for(int i=0;i<N;i++){
		for(int j= i+result;j<N;j++){
			if(arr[i]*p>=arr[j]){
				result = j-i+1;
			}else{
				break;
			}
		}
	}
	printf("%d",result);
	return 0;
}
