#include <stdio.h>
#include <stdlib.h>

int judge(char a, char b){
	if(a==b){
		return -1;
	}else if(a == 'C'){
		return b == 'J';
	}else if(a == 'B'){
		return b == 'C';
	}else if(a == 'J'){
		return b == 'B';		
	}
}

char max(int arr[]){
	char chs[3] = {'J','C','B'};
	int j = 0;
	int max = -1;
	for(int i = 0; i < 3; i++){
		if(arr[i] >= max){
			max = arr[i];
			j = i;
		}
	}
	return chs[j];
}

int main1018(){
	int N;
	int A_win = 0;
	int tie = 0;
	int A_win_count[3] = {0};
	int B_win_count[3] = {0};
	
	scanf("%d%c",&N);
	for(int i=0; i < N; i++){
		char a,b,space,re;
		scanf("%c%c%c%c",&a,&space,&b,&re);
		int result = judge(a,b);
		
		if(result == 1){
			A_win++;
			switch(a){
				case 'J': A_win_count[0]++;break;
				case 'C': A_win_count[1]++;break;
				case 'B': A_win_count[2]++;break;
			}
			
		}else if(result == 0){
			switch(b){
				case 'J': B_win_count[0]++;break;
				case 'C': B_win_count[1]++;break;
				case 'B': B_win_count[2]++;break;
			}
		}else if(result == -1){
			tie++;
		}
	}
	
	int B_win = N - A_win - tie;
	printf("%d %d %d\n",A_win,tie,B_win);
	printf("%d %d %d\n",B_win,tie,A_win);
	printf("%c %c",max(A_win_count),max(B_win_count));
	return 0;
}
