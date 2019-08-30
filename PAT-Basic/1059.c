#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}

int main1059(){
	int N,K,book[10000]={0};
	scanf("%d",&N);
	for(int i=1,id; i<=N;i++){
		scanf("%d",&id);
		book[id] = i;
	}
	scanf("%d",&K);
	for(int i=0,id;i<K;i++){
		scanf("%d",&id);
		if(id<0 || id>9999 || book[id] == 0){
			printf("%04d: Are you kidding?",id);
		}else if(book[id] == -1){
			printf("%04d: Checked",id);
		}else if(book[id] == 1){
			printf("%04d: Mystery Award",id);
			book[id] = -1;
		}else if(isPrime(book[id])){
			printf("%04d: Minion",id);
			book[id] = -1;			
		}else{
			printf("%04d: Chocolate",id);
			book[id] = -1;			
		}
		if(i!=K) printf("\n");
	}
	return 0;
}
