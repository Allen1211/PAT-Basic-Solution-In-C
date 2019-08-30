#include <stdio.h>
int main1006(){
    int n;
    scanf("%d",&n);
    while (n>=100){
        printf("B");
        n-=100;
    }
    while (n>=10){
        printf("S");
        n-=10;
    }
    int i=1;
    while (i<=n){
        printf("%d",i);
        i++;
    }

}

