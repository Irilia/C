#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0, b = 0;
	double sum = 0;//a是分子，b是分母
	for (b = 2; b <= 100; b++)
	{
		if (b % 2 == 0)
		{
			a = -1;
		}
		else
		{
			a = + 1;
		}
	    sum =sum+a*1.0/ b;
	}
	sum = sum + 1;
	printf("%lf",sum);
	system("pause");
	return 0;
}