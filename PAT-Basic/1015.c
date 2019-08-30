#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	int id;
	int D;
	int C;
	int sum;
}Node;
int N,L,H;

int classify(int D,int C){
	if(D >= H && C >= H)
    	return 1;
    else if(D >= H)
    	return 2;
    else if(D >= C)
    	return 3;	
	else
		return 4;
}

int comp1(const void *a,const void *b)
{
    Node *x = (Node*)a;
    Node *y = (Node*)b;
    int cls1 = classify(x->D,x->C);
    int cls2 = classify(y->D,y->C);
    
    if(cls1 != cls2)
    	return cls1 - cls2;
    else if(x->sum != y->sum)
    	return y->sum - x->sum;
    else if(x->D != y->D)
    	return y->D - x->D;
    else 
    	return x->id - y->id;

}
void print(Node *arr,int M){
	for(int i = 0;i < M; i++){
		printf("%d %d %d",arr[i].id,arr[i].D,arr[i].C);
		if(i!=M-1)
			printf("\n");
	}
}
int main1015(){
	int M = 0;
	scanf("%d %d %d",&N,&L,&H);
	Node *arr = malloc(sizeof(struct Student) * (N));
	for(int i=0;i<N;i++){
		int id,D,C;
		scanf("%d %d %d",&id,&D,&C);
		if(D >= L && C >= L){
			arr[M].id = id;
			arr[M].D = D;
			arr[M].C = C;
			arr[M].sum = D+C;
			M++;
		}
	}	
	qsort(arr,M,sizeof(struct Student),comp1);	
	printf("%d\n",M);
	print(arr,M);
	return 0;
}

