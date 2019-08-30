#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *mapping(int sum, char *str){
	char index[] = "0123456789";
	int digit = 0;
	int n = 0;
	do{
		digit = sum%10;
		str[n++] = index[digit]; 
		sum /= 10;
	} while(sum);
	str[n] = '\0';
	for(int i = 0,j = n-1;i < j;i++,j--){
		char temp;
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	return str;
}

char* out(char *str){
	int len = strlen(str) * 4 + 1;
	char *output = (char*)malloc(len);
	memset(output,'\0',len);
	for(char *p = str; *p != '\0';p++){
		switch(*p){
			case '0': strcat(output,"ling ");break; 
			case '1': strcat(output,"yi ");break; 
			case '2': strcat(output,"er ");break; 
			case '3': strcat(output,"san ");break; 
			case '4': strcat(output,"si ");break; 
			case '5': strcat(output,"wu ");break; 
			case '6': strcat(output,"liu ");break; 
			case '7': strcat(output,"qi ");break; 
			case '8': strcat(output,"ba ");break; 
			case '9': strcat(output,"jiu ");break; 
		}
	}
	int end = strlen(output) - 1;
	output[end] = '\0';
	return output;
}
int main1002(int argc, char *argv[]) {
	char str[100];
	int sum=0;
	while(scanf("%s",str) != EOF){
		int sum = 0;
		for(char *p = str; *p != '\0'; p++){
			sum += (int)(*p - '0');
		}
		char sumstr[10];
		mapping(sum,sumstr);
		char *output = out(sumstr);
		printf("%s\n",output);
	}
	
	return 0;
}


