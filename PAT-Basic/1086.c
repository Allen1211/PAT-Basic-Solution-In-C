#include <stdio.h>
#include <string.h>

int main1086(){
    char str[10];
    int a,b;
    scanf("%d %d",&a,&b);
    sprintf(str,"%d",a*b);
    int flag = 0;
    for(int i=strlen(str)-1;i>=0;i--){
        if(!flag && str[i]!='0')
            flag = 1;
        if(flag) putchar(str[i]);
    }
    return 0;
}
