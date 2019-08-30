#include <stdio.h>
#include <stdlib.h>

int main1023(){
	int arr[10];
	for(int i=0;i<10;i++){
		scanf("%d",arr+i);
	}
	for(int i=1;i<10;i++){
		if(arr[i]>0){
			printf("%d",i);
			arr[i]--;
			break;
		}
	}
	for(int i=0;i<10;i++){
		if(arr[i] > 0){
			while(arr[i]--)
				printf("%d",i);
		}
	}
	return 0;
}
