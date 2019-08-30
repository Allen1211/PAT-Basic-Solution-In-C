#include <stdio.h>
#include <stdlib.h>

typedef struct Person{
	char name[6];
	int year;
	int month;
	int day;
}Node;

int main1028(){
	int N,M = 0;
	scanf("%d",&N);
	Node *arr = malloc(sizeof(struct Person)*N);
	while(N--){
		char name[6];
		int y,m,d;
		scanf("%s %d/%d/%d",name,&y,&m,&d);
		
		int flag = 0;
		if(y == 1814)
			flag = m==9? (d>=6? 1:0):(m>9?1:0);
		else if(y == 2014)
			flag = m==9? (d<=6? 1:0):(m<9?1:0);
		else 
			flag = (y >2014 || y <1814) ?0:1;
		
		if(flag){
			strcpy(arr[M].name,name);
			arr[M].year = y;
			arr[M].month = m;
			arr[M].day = d;
			M++;
		}
	}
	
	int maxi=0,mini=0;
	for(int i = 0; i < M; i++){
		Node p = arr[i];
		Node max = arr[maxi];
		Node min = arr[mini];
		
		if(p.year <= max.year){
			if(p.year == max.year){
				if(p.month <= max.month){
					if(p.month == max.month){
						maxi = p.day < max.day ? i:maxi;
					}else{
						maxi = i;
					}
				}
			}else
				maxi = i;
		}
		
		if(p.year >= min.year){
			if(p.year == min.year){
				if(p.month >= min.month){
					if(p.month == min.month){
						mini = p.day > min.day ? i:mini;
					}else{
						mini = i;
					}
				}
			}else
				mini = i;
		}
			
	}
	if(M > 0)
		printf("%d %s %s",M,arr[maxi].name,arr[mini].name);
	else 
		printf("0");
	return 0;
	
	
}
