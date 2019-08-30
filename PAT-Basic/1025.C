#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	int next;
}Node;

Node memory[100000];

int main1025(){
	int head,N,K;
	scanf("%d %d %d",&head,&N,&K);
	for(int i=0;i<N;i++){
		int addr,val,next;
		scanf("%d %d %d",&addr,&val,&next);
		memory[addr].next = next;
		memory[addr].val = val;
	}
	
	int *arr = (int *)malloc(sizeof(int)*N);
	int n = 0;
	for(int p=head;p != -1;){
		arr[n++] = p;
		p = memory[p].next;
	}
	
	int begin = 0;
	int end = K-1;
	while(end <= n - n%K){
		for(int i = begin,j = end;i <j; i++,j--){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		begin += K;
		end += K;
	}
	for(int i=0;i < n-1;i++){
		printf("%05d %d %05d\n",arr[i],memory[arr[i]],arr[i+1]);
	}
	printf("%05d %d -1",arr[n-1],memory[arr[n-1]]);
	return 0;
}
