#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main1052(){
	char figure[3][11][5];
	int len[3] ={0};
	for(int i=0;i<3;i++){
		char ch;
		int n=1;
		while((ch = getchar())!='\n'){
			if(ch == '['){
			 	scanf("%[^]]",figure[i][n++]);
			}	
		}
		len[i] = n-1;
	}
	int K,lhand,leye,mouth,reye,rhand;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d %d %d %d %d",&lhand,&leye,&mouth,&reye,&rhand);
		if(lhand<=0 || leye<=0 ||mouth<=0 ||rhand<=0 || reye<=0 
            || lhand>len[0] || rhand>len[0] || leye>len[1] 
			|| reye>len[1] || mouth>len[2]){
			printf("Are you kidding me? @\\/@%s",i==K-1?"":"\n");
		}else{
			printf("%s(%s%s%s)%s",figure[0][lhand],figure[1][leye],figure[2][mouth],
								figure[1][reye],figure[0][rhand]);
			printf("%s",i==K-1?"":"\n");
		}
	}
	return 0;	
}
