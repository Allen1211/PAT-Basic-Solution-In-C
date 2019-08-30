#include <stdio.h>
#include <stdlib.h>

int main(){
	int N,book[37]={0},count=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int sum=0,n;
		scanf("%d",&n);
		while(n){
			sum += n%10;
			n/=10;
		}
		if(book[sum]==0) count++;
		book[sum]++;
	}
	printf("%d\n",count);
	for(int i=0,flag=1;i<37;i++){
		if(book[i] > 0){
			printf("%s%d",flag?"":" ",i);
			flag = 0;
		}
	}
	return 0;
}