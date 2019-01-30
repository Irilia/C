#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int print(int a)
{
	if (a < 10)
	{
		/*printf("%d\n", a);*/
		return a;
	}
	else
	{
		printf("%d\n",print(a / 10));
		/*printf("%d\n",a%10);*/
		return a % 10;
	}
}

int main()
{
	int a = 0;
	scanf("%d",&a);
	/*print(a);*/
	printf("%d\n", print(a));
	system("pause");
	return 0;
}