#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int min(int x, int y){
	return x<y? x:y;
}

int main1014(){
	char *week[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	
	char str1[61],
		str2[61],
		str3[62],
		str4[61];
	scanf("%s %s %s %s",str1,str2,str3,str4);
	int len1 = min(strlen(str1),strlen(str2));
	int flag = 1;
	for(int i = 0; i < len1; i++){
		if(flag){
			if(str1[i] == str2[i] &&str1[i] >= 'A' && str1[i] <= 'G'){
				int n = str1[i] - 'A';
				printf("%s ",week[n]);
				flag = 0;
			}	
		}else{
			if(str1[i] == str2[i]){
				if(str1[i] >= 'A' && str1[i] <= 'N') {
					int hour = (str1[i] - 'A'+ 1) + 9;
					printf("%d:",hour);
					break;
				}else if(isdigit(str1[i])){
					printf("0%c:",str1[i]);
					break;
				}else{
					continue;
				}
			}
		}
	}
	
	int len2 = min(strlen(str3),strlen(str4));
	for(int i = 0 ; i < len2; i++){
		if(str3[i] == str4[i] && isalpha(str3[i])){
			if(i < 10){
				printf("0%d",i);
			}else{
				printf("%d",i);
			}
			break;
		}
	}
	return 0;
}
