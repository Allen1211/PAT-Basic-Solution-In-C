#include <stdio.h>
int main(){
    int N,max=0,min=20001,maxid=0,minid=0;
    scanf("%d",&N);
    while(N--){
        int id,x,y,d;
        scanf("%d %d %d",&id,&x,&y);
        d = x*x+y*y;
        if(d > max){
            max = d;
            maxid = id;
        }
        if(d < min){
            min = d;
            minid = id;
        }
    }
    printf("%04d %04d",minid,maxid);
    return 0;
}