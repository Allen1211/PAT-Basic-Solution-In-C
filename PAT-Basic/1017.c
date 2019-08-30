#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Int(char x){
	return x-'0';
}
int main1017(){
	char A[1000];
	int B;
	int	R = 0;
	int	D = 0;
	scanf("%s %d",A,&B);
	
	if(strlen(A) == 1){
		printf("%d %d",Int(A[0])/B, Int(A[0])%B);
		return 0;
	}
	
	int start = 0;
	if(Int(A[start]) < B ){
		D += Int(A[start]);
		start++;
	}
	for(int i = start; i < strlen(A); i++){
		D = 10*D + Int(A[i]);
		putchar(D/B + '0');
		R = D%B;
		D = R;
	}
	printf(" %d",R);	
	return 0;
}
