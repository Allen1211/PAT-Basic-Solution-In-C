#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 145453
typedef struct Node{
	char name[7];
	double sum;
	int count;
}Node;
typedef struct Cell{
	char key[7];
	int val;
}Cell;

// BKDR Hash Function
unsigned int Hash(char *str)
{
    unsigned int seed = 31; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
 
    while (*str)
        hash = hash * seed + (*str++);
 
    return (hash & 0x7FFFFFFF) % SIZE;
}

int Find(Cell *map,const char *key){
	int hash = 	Hash(key);
	int step = 0;
	while(map[hash].val != -1 && strcmp(map[hash].key,key)!=0){
		hash += 2*(++step) - 1;
		if(hash >= SIZE)
			hash -= SIZE;
	}
	return hash;
}

int comp1085(const void *a,const void *b){
	Node *x = (Node*)a;
	Node *y = (Node*)b;
	if((int)(x->sum) != (int)(y->sum)){
		return (int)(y->sum) - (int)(x->sum);
	}else if(x->count != y->count){
		return x->count - y->count;
	}else{
		return strcmp(x->name,y->name);
	}
}

int main1085(){
	int N,M=0;
	Cell map[SIZE];
	for(int i=0;i<SIZE;i++){
		map[i].val = -1;
	}
	scanf("%d",&N);
	char id[7],temp[7];
	Node *arr = (Node*)malloc(sizeof(Node)*N);
	double score;
	for(int i=0;i<N;i++){
		scanf("%s %lf %s",id,&score,temp);
		for(int j=0;j<strlen(temp);j++){
			temp[j] = tolower(temp[j]);
		}
		switch(id[0]){
			case 'T': score = score * 1.5;break;
			case 'B': score = score / 1.5;break;
			default: break;
		}
		int hashidx = Find(map,temp);
		if(map[hashidx].val == -1){
			map[hashidx].val = M;
			memcpy(map[hashidx].key,temp,sizeof(char)*7);
			memcpy(arr[M].name,temp,sizeof(char)*7);
			arr[M].sum = score;
			arr[M].count = 1;
			M++;			
		}else{
			int index = map[hashidx].val;
			arr[index].sum += score;
			arr[index].count++;
		}
	}
	qsort(arr,M,sizeof(struct Node),comp1085);
	printf("%d\n",M);
	int rank = 0,pre = -1;
	for(int i=0;i<M;i++){
		if((int)(arr[i].sum) != pre){
			rank = i+1;
		}
		pre = (int)(arr[i].sum);
		printf("%d %s %d %d\n",rank,arr[i].name,(int)(arr[i].sum),arr[i].count);
	}
	return 0;
}
