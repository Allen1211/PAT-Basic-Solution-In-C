#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){
    int pg,ps,pk,ag,as,ak;
	scanf("%d.%d.%d",&pg,&ps,&pk);
    scanf("%d.%d.%d",&ag,&as,&ak);
	int ptotal = pg*17*29 + ps*29 + pk;
    int atotal = ag*17*29 + as*29 + ak;
    int delta = atotal - ptotal;
    if(delta < 0){
        printf("-");
        delta = -delta;
    }
	int g = delta / (29*17);
    delta = delta - g*29*17;
    int s = delta / 29;
    delta = delta - s*29;
    int k = delta;

	printf("%d.%d.%d",g,s,k);
	return 0;
}