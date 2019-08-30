#include <stdio.h>
#include <stdlib.h>



int main1001(int argc, char *argv[]) {
	
	int n=0;
	int step = 0;
	while((scanf("%d",&n) != EOF)){
		while(n > 1){
			if(n&1){
				n = 3*n + 1;
			}else{
				n /= 2;
			}
			step++;
		}
		printf("%d\n",step);
		step = 0;
	}
	return 0;
}
