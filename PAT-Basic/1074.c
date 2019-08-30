#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main1074(){
	int sys[20],A[20],B[20],sum[50]={0};
	int sys_cnt=0,na=0,nb=0,cnt=0;
	char ch;
	while((ch = getchar())!='\n'){
		sys[sys_cnt++] = ch-'0';
	}
	while((ch = getchar())!='\n'){
		A[na++] = ch-'0';
	}
	while((ch = getchar())!='\n'){
		B[nb++] = ch-'0';
	}	
	int add=0;
	while(sys_cnt > 0){
		int a=0,b=0;
		if(na > 0)  a = A[--na];
		if(nb > 0)  b = B[--nb];
		int s = sys[--sys_cnt];
		if(s==0) s = 10;
		sum[cnt++] = (a+b + add) % s;
		add = (a+b+add) / s;
	}
	sum[cnt++] = add;
	
	int begin = -1;
	for(int i=cnt-1;i>=0;i--){
		if(sum[i] != 0){
			begin = i;
			break;
		}
	}
	if(begin == -1){
		printf("0");
	}else{
		for(int i=begin;i>=0;i--){
			printf("%d",sum[i]);
		}
	} 
	return 0;
}
