#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int N,origin[101],arr[101]={1},lie[101]={0},w1=101,w2=101;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&origin[i]);
	}
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			int lie_cnt=0;
			for(int k=1;k<=N;k++){
				arr[k] = k==i||k==j? -1:1;
			}
			for(int k=1;k<=N;k++){
				if(arr[abs(origin[k])] * origin[k] < 0){
					lie[lie_cnt++] = k;
				}
			}
			if(lie_cnt==2&&arr[lie[0]]+arr[lie[1]]==0){
				if(i<w1||(i==w1&&j<w2)){
					w1 = i;
					w2 = j;
				}
			}
		}
	}
	if(w1!=101 && w2!=101){
		printf("%d %d",w1,w2);
	}else{
		printf("No Solution");
	}
	return 0;
}
