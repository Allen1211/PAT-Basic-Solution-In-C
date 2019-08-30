#include <stdio.h>
#include <stdlib.h>

int getM(int N){
	int m,min=100000;
	for(int i=N;i>0;i--){
		if(N%i!=0) continue;
		int delta = i - N/i;
		if(delta < 0){
			break;
		}
		if(delta < min){
			min = delta;
			m = i;
		}
	}
	return m;
}

int comp1050(int *x,int *y){
	return *y-*x;
}

void func1050(int **arr,int *in,int m,int n){
	int dx=0,dy=1;
	int N = m*n,x=0,y=0;
	int xend = m-1,yend=n-1,xbegin=1,ybegin=0;
	for(int i=0;i<N;i++){
		arr[x][y] = in[i];	
		if(dx==0&&dy==1){
			if(y == yend){
				dx = 1;
				dy = 0;
				yend--;
			}
		}else if(dx==1&&dy==0){
			if(x == xend){
				dx = 0;
				dy = -1;
				xend--;
			}
		}else if(dx==0&&dy==-1){
			if(y == ybegin){
				dx = -1;
				dy = 0;
				ybegin++;
			}
		}else if(dx==-1&&dy==0){
			if(x == xbegin){
				dx = 0;
				dy = 1;	
				xbegin++;			
			}		
		}
		x += dx;
		y += dy;
	}
}

int main1050(){
	int N;
	scanf("%d",&N);
	int m = getM(N);
	int n = N/m;
	
	int *in = (int *)malloc(sizeof(int)*N);
	
	int **arr = (int**)malloc(m * sizeof(int*));
	for(int i=0;i<m;i++){
		arr[i] = (int *)malloc( n * sizeof(int));
	}

	for(int i=0;i<N;i++){
		scanf("%d",in+i);
	}
	qsort(in,N,sizeof(int),comp1050);	
	func1050(arr,in,m,n);
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d%s",arr[i][j],j==n-1?"":" ");
		}
		if(i!=m-1)
			printf("\n");
	}
	
	
	return 0;
}
