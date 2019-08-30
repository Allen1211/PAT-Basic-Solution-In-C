#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Question{
	int points;		//分值 
	int choice_cnt;		//选项的数量 
	int r_choice_cnt;	//正确选项的数量 
	int r_choice[6];	//正确选项 1代表a --- 5代表e，值为1代表要选 
	int wrong_ans[6]; 	//这道题各个选项的错误次数 
}qarr[100];


//初始化题目信息 
void init(int N,int M){
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&(qarr[i].points),&(qarr[i].choice_cnt),&(qarr[i].r_choice_cnt));
		memset(qarr[i].r_choice,0,sizeof(int)*6);
		memset(qarr[i].wrong_ans,0,sizeof(int)*6); 
		char ch;
		while((ch = getchar())!='\n'){
			if(islower(ch)){
				qarr[i].r_choice[ch-'a'+1] = 1;		//标为正确选项 
				qarr[i].wrong_ans[ch-'a'+1] = N;	//正确选项默认错误N次，如果N个学生全答对，将递减至0次。 
			}
		}	
	}	
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	init(N,M);	//初始化题目信息 
	
	for(int i=0;i<N;i++){
		double score = 0.0;	//当前学生得分 
		for(int j=0;j<M;j++){
			int num_ans = 0,wrong=0;	//num_ans:输入正确答案的个数  flag: 为1表示有选错，为0表示没有选错 
			while(getchar()!='(');	 
			scanf("%d",&num_ans);
			char ans;
			while((ans = getchar()) != ')'){
				if(islower(ans)){
					if(qarr[j].r_choice[ans-'a'+1] != 1){
						qarr[j].wrong_ans[ans-'a'+1]++;
						wrong=1;
					}else{
						qarr[j].wrong_ans[ans-'a'+1]--;						
					}
				}
			}
				
			if(wrong){//情况1： 错选 ,没分 
				continue;
			}else if(num_ans == qarr[j].r_choice_cnt){// 情况2： 没有错选,且输入的选项数目等于正确选项的数目。 全对 
				score += (double)(qarr[j].points);
			}else{// 情况3： 没有错选，输入的选项数目小于正确选项的数目。 漏选
				score += (double)(qarr[j].points)/2.0;
			}
		}
		printf("%.1lf%s",score,i==N-1?"":"\n");	 
	}
	
	// 获得最大错误数 
	int max=0;
	for(int i=0;i<M;i++){
		for(int j=1;j<6;j++){
			if(qarr[i].wrong_ans[j] > max){
				max = qarr[i].wrong_ans[j];
			} 
		}		
	}
	
	if(max == 0){
		printf("\nToo simple");
	}else{
		for(int i=0;i<M;i++){
			for(int j=1;j<6;j++){// 错误次数等于最大错误数的 
				if(qarr[i].wrong_ans[j] == max){
					printf("\n%d %d-%c",max,i+1,(char)(j-1+'a'));
				} 
			}
		}
	}
	return 0;
}
