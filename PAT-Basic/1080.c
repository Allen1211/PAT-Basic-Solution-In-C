#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 57713
typedef struct Stu{
	char name[21];
	int pro;
	int mid;
	int final;
	int sum;
}Stu;

typedef struct Cell{
	char key[21];
	int val;
}Cell;

// BKDR Hash Function
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 31; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
 
    while (*str)
        hash = hash * seed + (*str++);
 
    return (hash & 0x7FFFFFFF) % SIZE;
}

int find(Cell *map,const char *key){
	int hash = 	BKDRHash(key);
	int step = 0;
	while(map[hash].val != -1 && strcmp(map[hash].key,key)!=0){
		hash += 2*(++step) - 1;
		if(hash >= SIZE)
			hash -= SIZE;
	}
	return hash;
}

int insert(Cell *map,const char *key, int val){
	int hash = find(map,key);
	if(map[hash].val == -1){
		map[hash].val = val;
		memcpy(map[hash].key,key,sizeof(char)*21);
		return 1;
	}	
	return 0;
}

int comp1080(Stu *a,Stu *b){
	if(a->sum == b->sum){
		return strcmp(a->name,b->name);
	}else{
		return b->sum - a->sum; // a>b -
	}
}

int main1080(){
	int P,M,N,count=0;
	Cell map[SIZE];
	Stu arr[10001];
	scanf("%d %d %d",&P,&M,&N);
	for(int i=0;i<SIZE;i++) 
		map[i].val=-1; 
	
	for(int i=0;i<P;i++){
		char name[21];
		int program;
		scanf("%s %d",name,&program);
		if(program >= 200){
			int flag = insert(map,name,count);
			memcpy(arr[count].name,name,sizeof(char)*21);
			arr[count].mid = -1;
			arr[count].final = -1;
			arr[count].pro = program>=0&&program<=900? program:-1;
			if(flag) count++;
		}
	}
	
	for(int i=0;i<M;i++){
		char name[21];
		int m;
		scanf("%s %d",name,&m);
		int hashidx = find(map,name);
		int idx = map[hashidx].val;
		if(idx != -1 ){
			arr[idx].mid = m<=100?m:-1;
		} 
		
	}
	for(int i=0;i<N;i++){
		char name[21];
		int f;
		scanf("%s %d",name,&f);
		int hashidx = find(map,name);
		int idx = map[hashidx].val;
		if(idx != -1){
			arr[idx].final = f<=100?f:-1;	
			if(arr[idx].mid > arr[idx].final){
				arr[idx].sum = (int)(arr[idx].mid * 0.4 + arr[idx].final*0.6 + 0.5);
			}else{
				arr[idx].sum = arr[idx].final;
			}
		}
	}
	qsort(arr,count,sizeof(struct Stu),comp1080);
	for(int i=0;i<count;i++){
		if(arr[i].sum >= 60)
			printf("%s %d %d %d %d\n",arr[i].name,arr[i].pro,arr[i].mid,arr[i].final,arr[i].sum);
	}
	return 0;
}
