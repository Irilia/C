#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int i = 0;
	int b = 1;
	int Sn = 0;
	printf("请输入一个数：");
	scanf("%d",&a);
	for (i = 0; i < 5; i++)
	{
		b = b * a;
		Sn = Sn + b;
	}
	printf("%d", Sn);
	system("pause");
	return 0;
}
