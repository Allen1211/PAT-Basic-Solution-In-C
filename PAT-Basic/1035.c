#include <stdio.h>
#include <stdlib.h>

/*
8
2 1 5 6 7 1 8 4
1 2 3 5 6 7 8 4

9
3 1 2 8 7 5 9 4 0
1 2 3 5 7 8 9 4 0

10
2 1 9 8 4 3 5 6 7 0
1 2 8 9 3 4 5 6 0 7

10
2 1 4 3 6 5 8 7 9 0
1 2 3 4 5 6 7 8 0 9

8
7 8 2 1 6 5 3 4
1 2 7 8 3 4 5 6

5
2 3 4 1 5
2 3 1 4 5
*/

int comp1035(int *x,int *y){
	return *x-*y;
}

void insertion(int *arr,int N){
	int count = 1;
	for(int i=0;i>=0;i++){
		if(arr[i] < arr[i+1]){
			count++;
		}else{
			break;
		}
	}
	int temp = arr[count];
	int j = 0;
	for(int i=count-1; i >= 0; i--){
		if(arr[i] < temp){
			j = i+1;
			break;	
		}
	}
	for(int i=count; i > j;i--){
		arr[i] = arr[i-1]; 
	}
	arr[j] = temp;
	return 0;
}

void merge(int arr[], int m, int N){
	for(int i=0;i < N/(2*m); i++){
		qsort(arr+(i*2*m),2*m,sizeof(int),comp1035);
	}
	if(N%m != 0){
		qsort(arr+N/(2*m)*(2*m),N-N/(2*m)*(2*m),sizeof(int),comp1035);
	}
}

int is_merge(int *a,int *b,int N){
	int flag = 0;
	int count = 1;
	for(int i=0;i+1<N;i++){
		if(b[i] < b[i+1]){
			count++;
		}else{
			break;
		}
	}		
	for(int i=count;i<N;i++){
		if(a[i] != b[i]){
			flag = 1;
			break;
		}
	}
	return flag;
}

int get_merge_part (int *arr,int N){
	int m=1;
	while(m <= N){
		m *= 2;
		for(int i=0;i+m<=N ; i+=m){
			for(int j=i;j+1<i+m;j++){
				if(arr[j] > arr[j+1]){
					return m/2;
				}
			}
		}	
	}
	if(m>=N){
		return m/2;
	}
	return m;
}

int main1035(){
	int N,a[100],b[100];
	scanf("%d",&N);
	for(int i=0;i < N;i++){
		scanf("%d",a+i);
	}
	for(int i=0;i < N;i++){
		scanf("%d",b+i);
	}	

	if(is_merge(a,b,N)){
		printf("Merge Sort\n");
		int m = get_merge_part(b,N);
		merge(b,m,N);		
	}
	else{
		printf("Insertion Sort\n");
		for(int i=0;i+1<N;i++){
			if(b[i] > b[i+1]){
				qsort(b,i+2,sizeof(int),comp1035);
				break;
			}
		}
	}
	for(int i=0;i<N;i++){
		printf("%d%s",b[i],i==N-1?"":" ");
	}

	
	return 0;
}
