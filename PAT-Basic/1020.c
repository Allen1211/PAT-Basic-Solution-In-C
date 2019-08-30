#include <stdio.h>
#include <stdlib.h>

typedef struct mooncake{
	float n;
	float total;
	float price;
}Node;

int comp1020(Node *x, Node *y){
	float result = x->price - y->price;
	if(result > 0)
		return -1;
	else if(result == 0)
		return 0;
	else
		return 1;
}

int main1020(){
	int N, need;
	scanf("%d %d",&N,&need);
	Node *arr = malloc(sizeof(struct mooncake)*N);
	for(int i = 0 ; i < N; i++){
		scanf("%f",&(arr[i].n));
	}
	for(int i = 0 ; i < N; i++){
		scanf("%f",&(arr[i].total));
		arr[i].price = arr[i].total / arr[i].n;
	}
	qsort(arr, N, sizeof(struct mooncake), comp1020);
	float sum = 0.0;
	for(int i = 0 ; i < N && need > 0; i++){
		if(need >= arr[i].n){
			sum += arr[i].total;
		}else{
			sum += arr[i].price * need;
		}
		need -= arr[i].n;
	}
	printf("%.2f",sum);
	return 0;
}
