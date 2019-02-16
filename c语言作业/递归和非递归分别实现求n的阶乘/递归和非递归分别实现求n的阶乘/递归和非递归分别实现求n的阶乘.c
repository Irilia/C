#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//
//int factorial(int n)//µÝ¹é
//{
//	if (n != 0)
//		return n * factorial(n - 1);
//	else
//		return 1;
//}

int factorial(int n)//·ÇµÝ¹é
{
	int i = 0;
	int sn = 1;
	for (i = 1; i <= n; i++)
	{
		sn = sn * i;
	}
	return sn;
}
int main()
{
	int n = 0;
	scanf("%d",&n);
	printf("%d",factorial(n));
	system("pause");
	return 0;
}