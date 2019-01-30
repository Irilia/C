#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int DigitSum(char* n)
//{
//	while (*n != '\0')
//	{
//		return (*n) + DigitSum(n+1);
//	}
//	return 0;
//}  
//
//
//int main()
//{
//	char* p = "123";
//	printf("%d",DigitSum(p));
//	system("pause");
//	return 0;
//}

int DigitSum(int p)
{
	if (p == 0)
	{
		return 0;
	}
	else
	{
		return p % 10 + DigitSum(p / 10);
	}
}


int main()
{
	int n = 0;
	printf("请输入一个数：");
	scanf("%d",&n);
	printf("%d", DigitSum(n));
	system("pause");
	return 0;
}