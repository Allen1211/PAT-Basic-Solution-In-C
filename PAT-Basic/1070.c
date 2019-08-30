#include <stdio.h>
#include <stdlib.h>

int comp1070(double *a,double *b){
	return *a-*b;
}

int main1070(){
	int N;
	scanf("%d",&N);
	double arr[N];
	for(int i=0;i<N;i++){
		scanf("%lf",arr+i);
	}
	qsort(arr,N,sizeof(double),comp1070);
	double len= arr[0];
	for(int i=1;i<N;i++){
		len = len/2 + arr[i]/2;
	}
	printf("%d",(int)len);
	return 0;
} 
