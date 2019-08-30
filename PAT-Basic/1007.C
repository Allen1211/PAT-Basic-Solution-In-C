#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main1007(){
	int N;
	scanf("%d",&N);
	int prime[10000] = { 0 };
	int *flag = (int*)malloc(sizeof(int)*(N+1));
	memset(flag,0,sizeof(int)*(N+1));
	int	i, j, count;
	for (i = 2, count = 0; i <= N; i++){
		if (!flag[i])              
			prime[count++] = i;
		for (j = 2 * i; j<N; j += i){  
			flag[j] = 1;
		}
	}
	int m=0;
	for (i = 0; i+1<count; i++){
		if(prime[i+1] - prime[i] == 2){
			m++;
		}
	} 
	printf("%d", m);
	return 0;
}
