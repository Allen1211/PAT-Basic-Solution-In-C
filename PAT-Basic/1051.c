#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main1051(){
	double R1,P1,R2,P2;
	scanf("%lf %lf %lf %lf",&R1,&P1,&R2,&P2);
	double A = R1*R2*cos(P1+P2);
	double B = R1*R2*sin(P1+P2);
	if(fabs(A) < 0.005)
		A = 0;
	if(fabs(B) < 0.005)
		B = 0;
	if(B<0.0){
		printf("%.2lf%.2lfi",A,B);
	}else{
		printf("%.2lf+%.2lfi",A,B);		
	}
	return 0;
} 
