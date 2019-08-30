#include <stdio.h>

int main(){
    int N,a=0,b=0;
    int a1,a2,b1,b2;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
        if(a2!=b2){
            if(a1+b1==a2){
                b++;
            }else if(a1+b1==b2){
                a++;
            }
        }
    }
    printf("%d %d",a,b);
    return 0;
}