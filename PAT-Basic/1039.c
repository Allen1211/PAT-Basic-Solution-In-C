#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main1039(){
	int ASCII[128] ={0};
	char sale[1001];
	char buy[1001];
	scanf("%s %s",sale,buy);
	for(int i=0;i<strlen(sale);i++){
		ASCII[(int)sale[i]]++;
	}
	int less = 0;
	for(int i=0;i<strlen(buy);i++){
		int want = (int)buy[i];
		if(ASCII[want] > 0){
			ASCII[want]--;
		}else{
			less++;
		}
	}
	if(less==0){
		int more=0;
		for(int i=0;i<128;i++){
			more += ASCII[i];
		}
		printf("Yes %d",more);
	}else{
		printf("No %d",less);
	}
	return 0;
}
