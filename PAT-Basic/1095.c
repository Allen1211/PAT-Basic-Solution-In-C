#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu{
	char id[14];
	int score;
}Stu;
Stu arrT[10000];
Stu arrA[10000];
Stu arrB[10000];
int comp1095(Stu *a,Stu *b){
	if(a->score == b->score){
		return strcmp(a->id,b->id);
	}else{
		return b->score - a->score;
	}
}

int main1095(){
	int N,M,score,cntT=0,cntA=0,cntB=0;
	char id[14];
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%s %d",id,&score);
		if(id[0]=='T'){
			arrT[cntT].score = score;
			memcpy(arrT[cntT].id,id,sizeof(char)*14);
			cntT++;
		}else if(id[0] == 'A'){
			arrA[cntA].score = score;
			memcpy(arrA[cntA].id,id,sizeof(char)*14);
			cntA++;
		}else{
			arrB[cntB].score = score;
			memcpy(arrB[cntB].id,id,sizeof(char)*14);
			cntB++;
		}
		
		
	}
	qsort(arrT,cntT,sizeof(struct Stu),comp1095);
	qsort(arrA,cntA,sizeof(struct Stu),comp1095);
	qsort(arrB,cntB,sizeof(struct Stu),comp1095);
	return 0;
}
