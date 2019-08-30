#include <stdio.h>
#include <math.h>

int main1062(){
    int N;
    scanf("%d",&N);
    double max =0.0;
    for(int i=0;i<N;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        double r = sqrt(a*a+b*b);
        if(r - max > 1e-8) max = r;
    }
    int t1 = (int)(max*100 + 0.5);
    max = (double)t1/100;
    printf("%.2lf",max);
    return 0;
}
