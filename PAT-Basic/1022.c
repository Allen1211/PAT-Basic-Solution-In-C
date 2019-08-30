#include <stdio.h>
#include <stdlib.h>

int main1022(){
	unsigned int a,b,S,sum;
	scanf("%u %u %u",&a,&b,&S);
	sum = a+b;
	if(sum == 0){
		putchar('0');
		return 0;
	}
	char stack[100];
	int top = -1;
	while(sum > 0){
		int temp = sum/S;
		stack[++top] = (sum - temp * S) + '0';
		sum = temp;
	}
	while(top >= 0){
		putchar(stack[top--]);
	}
	return 0;
}


