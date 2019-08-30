#include <stdio.h>
#include <stdlib.h>
int main1024(){
	char before_dot[10000];
	char after_dot[10000];
	int is_neg,b_count=0,a_count=0,exp;
	
	char ch = getchar();
	is_neg = ch=='-'? 1:0;
	while((ch = getchar())!='.'){
		before_dot[b_count++] = ch;
	}
	before_dot[b_count] = '\0';
	while((ch = getchar())!='E'){
		after_dot[a_count++] = ch;
	}
	after_dot[a_count] = '\0';
	scanf("%d",&exp);
	
	is_neg? printf("-"):printf("");
	if(exp == 0){
		printf("%s.%s",before_dot,after_dot);
	}else if(exp > 0){
		int zero_nums = exp - a_count;
		printf("%s",before_dot);
		if(exp >= a_count){
			printf("%s",after_dot);
		}else{
			for(int i=0;i<a_count;i++){
				if(i==exp) 
					putchar('.');
				putchar(after_dot[i]);
			}
		}
		while(zero_nums-- > 0){
			putchar('0');
		}
	}else if(exp < 0){
		int zero_nums = (-exp) - b_count;
		if(zero_nums >= 0){
			printf("0.");
			while(zero_nums-- > 0){
				putchar('0');
			}
			printf("%s%s",before_dot,after_dot);
		}else{
			for(int i=0;i<b_count;i++){
				if(i == b_count + exp) 
					putchar('.');
				putchar(before_dot[i]);
			}
			printf("%s",after_dot);			
		}
	}

	return 0;
}
