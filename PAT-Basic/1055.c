#include <stdio.h>
#include <stdlib.h>

typedef struct Person{
	char name[10];
	int h;
}P;

int comp1055(P *x, P *y){
	if(x->h == y->h){
		return strcmp(x->name,y->name);
	}else{
		return y->h - x->h;
	}
}

int main1055(){
	int N,K,per_row,last_row;
	scanf("%d %d",&N,&K);
	if(K > N)
		K = N;
	per_row = N/K;
	P* arr = (P*)malloc(sizeof(struct Person)*N);
	for(int i=0;i<N;i++){
		scanf("%s %d",arr[i].name,&(arr[i].h));
	}
	qsort(arr,N,sizeof(struct Person),comp1055);
	
	for(int i=0;i<N;){
		int row_num = i==0? per_row+N%K: per_row;
		int n;
		if(row_num == 1){
			n = 0;
		}else if(row_num%2==0){
			n = row_num-1;
		}else{
			n = row_num-2;
		}
		
		for(int j=0;j<row_num;j++){	
			printf("%s%s",arr[i+n].name,j==row_num-1?"":" ");
			if(n == 1){
				n = 0;
			}else if(n%2==1){
				n -= 2;
			}else if(n%2==0){
				n += 2;
			}
		}
		i += row_num;
		if(i<N){
			printf("\n");
		}
	}
	
	return 0;
}
