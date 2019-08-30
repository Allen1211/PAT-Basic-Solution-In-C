#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isprime(int n){
	int flag=1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			flag=0;
			break;
		}
	}
	return flag;
}
int main1094(){
	int L,K;
	char num[1001];
	scanf("%d %d",&L,&K);
	scanf("%s",num);
	for(int i=0;i+K<=strlen(num);i++){
		int n = 0,cnt=0;
		for(int j=i;j<i+K;j++){
			n = n*10 + num[j]-'0';
		}
		for(int temp =n; temp!=0;){
			cnt++;
			temp/=10;
		}
		if(isprime(n)){
			while(K>cnt) {
				putchar('0');
				cnt++;
			}
			printf("%d",n);
			return 0;
		}
	}
	printf("404");
	return 0;
}
