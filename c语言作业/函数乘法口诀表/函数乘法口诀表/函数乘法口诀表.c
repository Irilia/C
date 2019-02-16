#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>



void mul_table(int a)
{
	int i = 0;
	int b = 0;
	int c = 0;
	for (c = 1; c <= a; c++)
	{
		for (i = 1; i <= c; i++)
		{
			b = c * i;
			printf("%d*%d=%-2d  ",c,i,b);
		}
		printf("\n");
	}
}

int main()
{
	int x = 0;
	scanf("%d",&x);
	mul_table(x);
	system("pause");
	return 0;
}
