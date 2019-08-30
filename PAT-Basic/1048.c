#include <stdio.h>
#include <stdlib.h>
char figure[13] = {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
int main1048(){
	int A[100],B[100],na=0,nb=0,nc=0;
	char C[100];
	char ch;
	while((ch=getchar())!=' '){
		A[na++] = (int)(ch-'0');
	}
	while((ch=getchar())!='\n'){
		B[nb++] = (int)(ch-'0');
	}
	if(nb < na){
		
	}	
	int count = 1;
	while(na && nb){
		if(count%2==1){
			int n = (B[--nb] + A[--na])%13;
			C[nc++] = figure[n];
 		}else{
 			int n = B[--nb] - A[--na];
 			if(n<0) n+=10;
			C[nc++] = figure[n]; 			
		 }
		count++;
	}
	while(nb){
		C[nc++] = (char)(B[--nb] + '0');
	}
	while(nc){
		putchar(C[--nc]);
	}
	return 0;
}
