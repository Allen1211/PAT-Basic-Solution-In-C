#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CLK_TCK 100
#define sec_per_hour 3600
#define sec_per_minute 60

int main1026(){
	int begin,end;
	scanf("%d %d",&begin,&end);
	float temp = (end - begin) * 1.0/ CLK_TCK * 10;
	int temp2 = (int)(temp + 0.5) ;
	float temp3 = temp2 / 10.0;
	int delta_sec = (int)(temp3 + 0.5);
	
	int hour = delta_sec / sec_per_hour;
	delta_sec = delta_sec - hour*sec_per_hour;
	int minute = delta_sec / sec_per_minute;
	delta_sec = delta_sec - minute*sec_per_minute;
	int sec = delta_sec;
	
	printf("%02d:%02d:%02d",hour,minute,sec);
	return 0;
}
