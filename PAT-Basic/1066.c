#include <stdio.h>
#include <stdlib.h>

int main1066(){
	int N,M,A,B,h;
	scanf("%d %d %d %d %d",&N,&M,&A,&B,&h);

	int tmp;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&tmp);
			if(tmp >= A && tmp <=B){
				tmp = h;
			}
			printf("%s%03d",j==0?"":" ",tmp);
		}
		if(i!=N-1) printf("\n");
	}
	return 0;
}
