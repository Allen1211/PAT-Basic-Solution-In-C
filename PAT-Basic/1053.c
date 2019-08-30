#include <stdio.h>
#include <stdlib.h>

int main1053(){
	int N,D,may_empty=0,empty=0;
	double e;
	scanf("%d %lf %d",&N,&e,&D);
	for(int i=0;i<N;i++){
		int K,count=0;
		double E;
		scanf("%d",&K);
		for(int j=0;j<K;j++){
			scanf("%lf",&E);
			if(E < e) count++;
		}
		if(count > K/2){
			if(K > D) empty++;
			else may_empty++;
		}
	}
	double p1 = (double)may_empty / N * 100;
	double p2 = (double)empty / N *100;
	printf("%.1lf%c %.1lf%c",p1,'%',p2,'%');
	return 0;
	
}
