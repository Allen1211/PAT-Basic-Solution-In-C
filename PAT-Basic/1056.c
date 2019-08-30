#include <stdio.h>

int main(){
    int N,sum=0,num;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        sum += num*10*(N-1) + num*(N-1);
    }
    printf("%d",sum);
    return 0;
}