#include "stdio.h"
#include "stdlib.h"
int main1012()
{
	int N;
	int A1,A2,A3,A5;
	A1 = A2 = A3 = A5 = 0;
	int flag_2 = -1;
	double A4;
	A4 = 0.0;
	int count_1,count_2,count_3,count_4,count_5;
	count_1 = count_2 = count_3 = count_4 = count_5 = 0;
	scanf("%d",&N);
	int * array = (int *)malloc(N * sizeof(int));
	int i;
	for(i = 0; i < N; i++)
	{
		scanf("%d",&array[i]);
	}
	for(i = 0; i < N; i++)
	{
		switch(array[i] % 5)
		{
			case 0:	
				if(array[i] % 2 == 0)
				{
					A1 += array[i];
					count_1++; 
				}				
				break;
			case 1: 
				flag_2 *= -1;
				A2 += flag_2*array[i];
				count_2++;
				break;
			case 2:
				count_3++;
				break;
			case 3:
				count_4++;
				A4 += array[i]; 
				break;
			case 4:
				if(A5 < array[i])
					A5 = array[i];
				count_5++;
				break;
			default: break;								
		}
	}
 
	A4 = A4 / count_4;
	if(count_1 == 0)
		printf("N ");
	else 
		printf("%d ",A1);
	if(count_2 == 0)
		printf("N ");
	else 
		printf("%d ",A2);
	if(count_3 == 0)
		printf("N ");
	else 
		printf("%d ",count_3);
	if(count_4 == 0)
		printf("N ");
	else 
		printf("%.1f ",A4);
	if(count_5 == 0)
		printf("N");
	else 
		printf("%d",A5);
	
	return 0;
}

