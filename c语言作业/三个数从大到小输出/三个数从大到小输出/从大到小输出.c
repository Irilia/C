#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0, b = 0, c = 0, i = 0;
	printf("请输入三个数：");
	scanf("%d%d%d", &a,&b,&c);
	if (a < b)
	{
		i = a;
		a = b;
		b = i;
	}
	if (a < c)
	{
		i = a;
		a = c;
		c = i;
	}
	if (b < c)
	{
		i = b; b = c;
		c = i;
	}
    printf("%d%d%d",a,b,c );
	system("pause");
	return 0;
}