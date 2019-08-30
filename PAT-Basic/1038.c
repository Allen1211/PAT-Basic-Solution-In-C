#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int book[101] = {0};
    for(int i=0;i<N;i++){
        int score;
        scanf("%d",&score);
        book[score]++;
    }
    int M;
    scanf("%d",&M);
    while(M--){
        int score;
        scanf("%d",&score);
        printf("%d%s",book[score],M==0?"":" ");
    }
    return 0;
}