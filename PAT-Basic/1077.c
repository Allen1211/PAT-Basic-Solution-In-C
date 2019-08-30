#include <stdio.h>
#include <stdlib.h>

int main1077(){
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		int valid_cnt=0;
		double result=0,stu=0,temp,teacher=0,max=-1,min=101;
		for(int i=0;i<N;i++){
			if(i==0){
				scanf("%lf",&teacher);
			}else{
				scanf("%lf",&temp);
				if(temp >= 0 && temp <=M){
					if(temp > max) max = temp;
					if(temp < min) min = temp;
					stu += temp;
					valid_cnt++;
				}
			}
		}
		stu -= max + min;
		valid_cnt -= 2;
		result = (teacher + stu / valid_cnt) / 2;
		printf("%d%s",(int)(result+0.5),i==N-1?"":"\n");
	}
	return 0;
}
