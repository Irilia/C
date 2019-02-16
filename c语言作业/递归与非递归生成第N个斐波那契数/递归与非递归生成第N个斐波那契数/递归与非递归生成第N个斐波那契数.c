#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int fib(int a)//µÝ¹é
//{
//	if (a <= 2)
//	{
//		return 1;
//	}
//	else
//		return fib(a - 1) + fib(a - 2);
//}

int fib(int i)//·ÇµÝ¹é
{
	int j = 0;
	int a = 1;
	int b = 1;
	int c = 0;
	if (i <= 2)
	{
		return 1;
	}
	else
	{
		for (j = 2; j < i; j++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}
int main()
{
	int i = 0;
	int n = 0;
	scanf("%d",&i);
	printf("%d", fib(i));
	system("pause");
	return 0;
}