#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int id;
	struct Node *next;
}Node;

typedef struct Cell{
	int flag;
	int exist;
	Node *head;
}Cell;

Cell book[100000];

Node* add(Node *head,int val){
	if(head == NULL){
		head = (Node*)malloc(sizeof(struct Node));
		head->next = NULL;
		head->id = val;
	}else{
		Node *a = (Node*)malloc(sizeof(struct Node));
		a->id = val;
		a->next = head->next;
		head->next = a;
	}
	return head;
}

int main1090(){
	int N,M,K;
	scanf("%d %d",&N,&M);
	int a,b;
	for(int i=0;i<N;i++){
		scanf("%d %d",&a,&b);
		book[a].flag = 1;
		book[b].flag = 1;
		book[a].head = add(book[a].head,b);
		book[b].head = add(book[b].head,a);
	}
	for(int i=0;i<M;i++){
		scanf("%d",&K);
		int id,cnt=0;int arr[1000];
		for(int j=0;j<K;j++){
			scanf("%d",&id);
			if(book[id].flag == 1){
				book[id].exist = i+1;
				arr[cnt++] = id;
			}
		}
		int flag = 1;
		for(int j=0;j<cnt&&flag;j++){
			for(Node *p=book[arr[j]].head;p!=NULL;p=p->next){
				if(book[p->id].exist == i+1){
					flag = 0;
					break;
				}
			}	
		}
		printf("%s\n",flag?"Yes":"No");
	}
	return 0;
}

