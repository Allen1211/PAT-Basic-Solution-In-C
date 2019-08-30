#include <stdio.h>
#include <math.h>
int main1083(){
    int book[100001]={0};
    int N,num;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&num);
        book[abs(num-i)]++;
    }
    for(int i=100000;i>=0;i--){
        if(book[i] > 1){
            printf("%d %d\n",i,book[i]);
        }
    }
    return 0;
}
