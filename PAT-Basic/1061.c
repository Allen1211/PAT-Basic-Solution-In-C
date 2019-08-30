#include <stdio.h>
#include <stdlib.h>

int GCD(int x, int y)
{	
	return y==0? x:GCD(y,x%y);
}

int main1061(){
	int N1,M1,N2,M2,K;
	scanf("%d/%d %d/%d %d",&N1,&M1,&N2,&M2,&K);
	double from = (double)N1*K/M1;
	double to = (double)N2*K/M2;
	if(from - to > 1e-8){
		double temp = from;
		from = to;
		to = temp;
	}
	int count=0;
	for(int i=from+1;i<to;i++){
		if(GCD(i,K) == 1){
			printf("%s%d/%d",count==0?"":" ",i,K);
			count++;
		}
	}
	return 0;
}
