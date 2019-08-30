#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int signup;
	int mate;
}Node;

Node couple[100000];

int comp1064(int *x,int *y){
	return *x-*y;
}

int main1064(){
	int N,M;
	scanf("%d",&N);
	int a,b;
	for(int i=0;i<N;i++){
		scanf("%d %d",&a,&b);
		couple[a].signup = 1;
		couple[a].mate = b;
		couple[b].signup = 1;
		couple[b].mate = a;
	}
	scanf("%d",&M);
	int *arr = (int*)malloc(sizeof(int)*M);
	int *ans = (int*)malloc(sizeof(int)*M);
	for(int i=0;i<M;i++){
		scanf("%d",&arr[i]);
		if(couple[arr[i]].signup == 1){
			couple[arr[i]].signup = 2;
		}
	}
	int count=0,id;
	for(int i=0;i<M;i++){
		id = arr[i];
		if(couple[id].signup != 2 || couple[couple[id].mate].signup != 2){
			ans[count++] = arr[i];
		}
	}	
	qsort(ans,count,sizeof(int),comp1064);		
	printf("%d\n",count);
	for(int i=0;i<count;i++){
		printf("%05d%s",ans[i],i==count-1?"":" ");
	}
	return 0;
}

