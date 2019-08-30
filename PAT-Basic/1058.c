#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Question{
	int points;
	int choice;
	int right;
	int r_choice[6];
	int wrong;
}Q;

int main1058(){
	int N,M;
	scanf("%d %d",&N,&M);
	Q qarr[100];
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&(qarr[i].points),&(qarr[i].choice),&(qarr[i].right));
		for(int j=0;j<6;j++) qarr[i].r_choice[j] = 0;
		qarr[i].wrong = 0;
		char ch;
		while((ch = getchar())!='\n'){
			if(islower(ch)){
				qarr[i].r_choice[ch-'a'+1] = 1;
			}
		}	
	}
	int max=0;
	for(int i=0;i<N;i++){
		int score = 0;
		for(int j=0;j<M;j++){
			int num_ans = 0,flag = 1;
			while(getchar()!='(');
			scanf("%d",&num_ans);
			if(num_ans != qarr[j].right){
				qarr[j].wrong++;
				flag = 0;
			}else{
				char ans;
				while((ans = getchar()) != ')'){
					if(islower(ans)){
						if(qarr[j].r_choice[ans-'a'+1] != 1){
							qarr[j].wrong++;
							flag=0;
							break;
						}
					}
				}
				if(flag) score+=qarr[j].points;
				if(qarr[j].wrong > max) 
					max = qarr[j].wrong;
			}	
		}
		printf("%d\n",score);
	}
	if(max == 0){
		printf("Too simple");
	}else{
		printf("%d",max);
		for(int i=0;i<M;i++)
			if(qarr[i].wrong == max)
				printf(" %d",i+1);
	}

	
	return 0;
}
