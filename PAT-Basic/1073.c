#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Question{
	int points;		//��ֵ 
	int choice_cnt;		//ѡ������� 
	int r_choice_cnt;	//��ȷѡ������� 
	int r_choice[6];	//��ȷѡ�� 1����a --- 5����e��ֵΪ1����Ҫѡ 
	int wrong_ans[6]; 	//��������ѡ��Ĵ������ 
}qarr[100];


//��ʼ����Ŀ��Ϣ 
void init(int N,int M){
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&(qarr[i].points),&(qarr[i].choice_cnt),&(qarr[i].r_choice_cnt));
		memset(qarr[i].r_choice,0,sizeof(int)*6);
		memset(qarr[i].wrong_ans,0,sizeof(int)*6); 
		char ch;
		while((ch = getchar())!='\n'){
			if(islower(ch)){
				qarr[i].r_choice[ch-'a'+1] = 1;		//��Ϊ��ȷѡ�� 
				qarr[i].wrong_ans[ch-'a'+1] = N;	//��ȷѡ��Ĭ�ϴ���N�Σ����N��ѧ��ȫ��ԣ����ݼ���0�Ρ� 
			}
		}	
	}	
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	init(N,M);	//��ʼ����Ŀ��Ϣ 
	
	for(int i=0;i<N;i++){
		double score = 0.0;	//��ǰѧ���÷� 
		for(int j=0;j<M;j++){
			int num_ans = 0,wrong=0;	//num_ans:������ȷ�𰸵ĸ���  flag: Ϊ1��ʾ��ѡ��Ϊ0��ʾû��ѡ�� 
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
				
			if(wrong){//���1�� ��ѡ ,û�� 
				continue;
			}else if(num_ans == qarr[j].r_choice_cnt){// ���2�� û�д�ѡ,�������ѡ����Ŀ������ȷѡ�����Ŀ�� ȫ�� 
				score += (double)(qarr[j].points);
			}else{// ���3�� û�д�ѡ�������ѡ����ĿС����ȷѡ�����Ŀ�� ©ѡ
				score += (double)(qarr[j].points)/2.0;
			}
		}
		printf("%.1lf%s",score,i==N-1?"":"\n");	 
	}
	
	// ����������� 
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
			for(int j=1;j<6;j++){// ��������������������� 
				if(qarr[i].wrong_ans[j] == max){
					printf("\n%d %d-%c",max,i+1,(char)(j-1+'a'));
				} 
			}
		}
	}
	return 0;
}
