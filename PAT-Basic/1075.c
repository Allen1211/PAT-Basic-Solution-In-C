#include <stdio.h>
#include <stdlib.h>

int main1075(){
	int head,N,K,list[100001]={-1},data[100001]={0},output[100001]={-1},cnt=0;
	scanf("%d %d %d",&head,&N,&K);
	for(int i=0;i<N;i++){
		int addr,d,next;
		scanf("%d %d %d",&addr,&d,&next);
		list[addr] = next;
		data[addr] = d;
	}
	for(int i=head;i!=-1;i = list[i]){
		if(data[i] < 0)
			output[cnt++] = i;
	}
	for(int i=head;i!=-1;i = list[i]){
		if(data[i]>=0 && data[i] <= K)
			output[cnt++] = i;
	}
	for(int i=head;i!=-1;i = list[i]){
		if(data[i] > K)
			output[cnt++] = i;
	}	
	for(int i=0;i<cnt;i++){
		printf("%05d %d ",output[i],data[output[i]]);
		if(i != cnt-1){
			printf("%05d\n",output[i+1]);
		}else{
			printf("-1");
		}
	}
	return 0;		
}
