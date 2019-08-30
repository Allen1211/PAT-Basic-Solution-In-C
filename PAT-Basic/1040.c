#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main1040(){	
	long long sum=0;
	int P=0,A=0,T=0;
	char str[100001];
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++){
		if(str[i] == 'T')
			T++;
	}
	for(int i=0;i<strlen(str);i++){
		switch(str[i]){
			case 'P': P++; break;
			case 'A': sum+= (P*T)%1000000007; break;
			case 'T': T--; break;
		}
	}
	
	printf("%d",sum%1000000007);
	return 0;
}
