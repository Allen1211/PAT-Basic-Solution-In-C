#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d",&N);
    int team,person,score;
    int *arr = (int*)malloc(sizeof(int)*1001);
    memset(arr,0,sizeof(int)*(1001));
    for(int i=0;i<N;i++){
        scanf("%d-%d %d",&team,&person,&score);
        arr[team] += score;
    }
    int maxteam = 1;
    for(int i=1;i<=1000;i++){
        if(arr[i] > arr[maxteam]){
            maxteam = i;
        }
    }
    printf("%d %d",maxteam,arr[maxteam]);
    return 0;
}