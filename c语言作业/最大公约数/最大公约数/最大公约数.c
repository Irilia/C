#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0, b = 0,i=0;
	printf("��������������");
	scanf("%d%d", &a, &b);
	if (a > b)
	{
		for(i=b;i>=1;i--)
			if ((a%i == 0) && (b%i == 0))
			{
				printf("���Լ��Ϊ��%d\n", i);
				break;
			}
	}
	else
	{
		for(i=a;i>=1;i--)
			if ((a%i == 0) && (b%i == 0))
			{
				printf("���Լ��Ϊ��%d\n", i);
				break;
			}
	}
	system("pause");
	return 0;
}