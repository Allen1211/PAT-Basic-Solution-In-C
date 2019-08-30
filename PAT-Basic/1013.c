#include <stdio.h>
#include <stdlib.h>

int main1013(){
	int M,N;
	scanf("%d %d",&M,&N);
	int count = 0;
	int num = 0;
	for(int i = 2;;i++){
		if(i%2==0 && i!=2){
			continue;
		}
		int flag=1;
		for(int j=2; j*j<=i;j++){
			if(i%j==0){
				flag=0;
				break;
			}
		}
		if(flag){
			count++;
			if(count >= M){
				num++;
			}
			if(count < M){
				continue;
			}else if(count>=M && count <= N){
				if(count == N){
					printf("%d",i);
				}else{
					printf("%d",i);
					if(num % 10 == 0){
						printf("\n");
					}else{
						printf(" ");
					}
				}
			}else{
				break;
			}
		}
		

	}
	return 0;
}
