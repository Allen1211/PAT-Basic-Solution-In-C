#include <stdio.h>
#include <stdlib.h>

int main1071(){
	int T,K;
	scanf("%d %d",&T,&K);
	for(int i=0;i<K;i++){
		int n1,b,t,n2;
		scanf("%d %d %d %d",&n1,&b,&t,&n2);
		if(t > T){
			printf("Not enough tokens.  Total = %d.",T);
		}else{
			if(n1>n2 && b==1 || n2>n1&&b==0){
				T -= t;
				printf("Lose %d.  Total = %d.",t,T);
			}else{
				T += t;
				printf("Win %d!  Total = %d.",t,T);
			}
		}
		
		if(T <= 0){
			printf("\nGame Over.");
			break;
		}else if(i!= K-1){
			printf("\n");
		}
	}
	return 0;
}
