#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* Compress(char *str,int n){
	if(n == 1){
		return str;
	}
    int m = 0,count=1;
    char next[100000];
    char pre = str[0];
	for(int i=1;i<strlen(str);i++){
		if(str[i] != pre){
			next[m++] = pre;
            next[m++] = count+'0';
			count = 1;
		}else{
			count++;
		}
		pre = str[i];
	}
	next[m++] = pre;
    next[m++] = count+'0';
    next[m] = '\0';
	str = next;
	return Compress(str,n-1);
}
int main1084(){
	int N;
	char str[2];
	scanf("%s %d",str,&N);
	char *result = Compress(str,N);
	printf("%s",result);
	return 0;
}
