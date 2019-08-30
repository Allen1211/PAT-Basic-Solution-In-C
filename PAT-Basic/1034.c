#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int GUN(long long x, long long y)
{	
	if(x==0 || y==0){
		return 1;
	}
	x = abs(x);
	y = abs(y);
	long long z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;	
	}
	return z;
}

void print1034(long long a,long long b){
	if(b == 0){
		printf("Inf");
	}else if(a == 0){
		printf("0");
	}else if(a % b == 0){
		if(a<0)
			printf("(%d)",a/b);
		else
			printf("%d",a/b);
	}else if(abs(a) > abs(b)){
		if(a<0)
			printf("(%d %d/%d)",a/b,(-a)%b,b);
		else
			printf("%d %d/%d",a/b,a%b,b);
	}else {
		if(a<0)
			printf("(%d/%d)",a,b);
		else
			printf("%d/%d",a,b);
	}
}

void func1034(long long a1,long long b1,long long a2,long long b2,char oper){
	long long r1 = GUN(a1,b1);
	long long r2 = GUN(a2,b2);
	print1034(a1/r1,b1/r1);
	printf(" %c ",oper);
	print1034(a2/r2,b2/r2);
	printf(" = ");
	long long a,r;
	long long b = b1*b2;
	switch(oper){
		case '+':{
			a = a1*b2+a2*b1;
			r = GUN(a,b);
			print1034(a/r, b/r);
			printf("\n");
			break;
		}
		case '-':{
			a = a1*b2-a2*b1;
			r = GUN(a,b);
			print1034(a/r, b/r);
			printf("\n");
			break;
		}
		case '*':{
			a = a1*a2;
			r = GUN(a,b);
			print1034(a/r, b/r);
			printf("\n");
			break;
		}
		case '/':{
			a = a1 * b2;
			b = b1 * a2;
			r = GUN(a,b);
			if(a1*a2 < 0){
				print1034(-abs(a/r),abs(b/r));
			}else{
				print1034(abs(a/r),abs(b/r));
			}
			break;
		}
	}
}

int main1034(){
	long long a1,b1,a2,b2,r;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	func1034(a1,b1,a2,b2,'+');
	func1034(a1,b1,a2,b2,'-');
	func1034(a1,b1,a2,b2,'*');
	func1034(a1,b1,a2,b2,'/');
	
	return 0;
}
