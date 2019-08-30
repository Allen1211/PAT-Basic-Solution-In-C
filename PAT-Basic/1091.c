#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main1091(){
	int M,flag,len,Kval;
	char result[10],K[5],*p;
	scanf("%d",&M);
	while(M--){
		scanf("%s",&K);
		len = strlen(K);
		Kval = atoi(K);
		flag = 0;
		for(int i=1;i<10;i++){
			sprintf(result,"%d",i*Kval*Kval);
			p = result + strlen(result) - len;
			if(atoi(p) == Kval){
				printf("%d %d\n",i,atoi(result));
				flag = 1;
				break;
			}
		}
		if(!flag) printf("No\n");
	}
	return 0;
}
