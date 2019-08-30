#include <stdio.h>
#include <stdlib.h>

int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};

int main1031(){
	int N,all_pass=1;
	char id[19];
	scanf("%d",&N);
	while(N--){
		scanf("%s",id);
		int sum=0;
		for(int i=0;i < 17;i++){
			sum += (id[i]-'0') * weight[i];
		}
		char core = M[sum%11];
		if(core != id[17]){
			all_pass = 0;
			printf("%s\n",id);
		}
	}	
	if(all_pass){
		printf("All passed");
	}
	return 0;
}
