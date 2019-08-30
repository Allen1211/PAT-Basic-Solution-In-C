#include <stdio.h>
#include <string.h>

char* f(double P,double M){
	char *s1 = "Cong",*s2 = "Ping",*s3 = "Gai";
	return P>M? "Cong":(P==M?"Ping":"Gai");
}

int main1088(){
	int M,X,Y,A,B;
	double C;
	scanf("%d %d %d",&M,&X,&Y);
	int flag=0;
	for(A=99;A>=10;A--){
		B = A%10 *10 + A/10;
		C = (double)abs(A-B)/X;
		if(B*1.0 == C*Y){
			flag = 1;
			break;			
		}
	}
	if(flag == 0){
		printf("No Solution");
	}else{
		printf("%d",A);
		printf(" %s %s %s",f(A*1.0,M*1.0),f(B*1.0,M*1.0),f(C*1.0,M*1.0));
	}
	return 0;
}
