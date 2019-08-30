#include <stdio.h>

int main1010(){
	int a,n;
	int count = 0;
	while(scanf("%d %d",&a,&n)!=EOF){
		if(n == 0){
			printf("0 0");
			return 0;
		}
		if(count != 0){
			printf(" ");
		}		
		count++;
		if(n == 0){
			continue;
		}
		printf("%d %d",a*n,n-1);

	}
	return 0;
}
