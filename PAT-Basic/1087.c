#include <stdio.h>
#include <string.h>
int book[11000] = {0};
int main1087(){
	int N,sum,count=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		sum = i/2 + i/3 + i/5;
		if(book[sum] != 1){
			count++;
			book[sum] = 1;
		} 
	}
	printf("%d",count);
	return 0;
}
