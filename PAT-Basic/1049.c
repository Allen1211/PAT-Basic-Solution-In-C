#include <stdio.h>
#include <stdlib.h>

int main1049(){
	int N;
	double val,result=0.0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%lf",&val);
		result += val *i*(N-i+1);
	}
	printf("%.2lf",result);
	return 0;
}
