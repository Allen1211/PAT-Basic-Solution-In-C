#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(char str[]){
	int m = 0,n = 0,k = 0;
	int P_pos = -1, T_pos = -1;
	int T_flag = 0;
	for(int i = 0 ; i < strlen(str); i++){
		char ch = str[i];
		if(ch != 'P' && ch != 'A' && ch!='T'){
			return 0;
		}
		if(ch == 'P'){
			if(P_pos != -1){
				return 0;
			}
			P_pos = i;	
		}
		if(ch == 'T'){
			if(T_pos != -1){
				return 0;
			}
			T_pos = i;
			T_flag = 1;
		}	
		
		if(T_pos > P_pos && T_flag != 1){
			return 0;
		}
		
	}
	
	m = P_pos;
	n = T_pos - P_pos - 1;
	k = strlen(str) - T_pos - 1;
	return n > 0 && k == n * m;
	

}

int main1003(int argc, char *argv[]) {
	
	int n=0;
	scanf("%d",&n);
	char str[101];
	while(n--){
		scanf("%s",&str);
		if(check(str)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
