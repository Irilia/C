#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void print(int n)//125 12
{
	if (n > 9)
	{
		print(n / 10);//12 1
	}
	printf("%d ", n % 10);//1 2 5
}
int main()
{
	int a = 0;
	int x = 0;
	scanf("%d", &a);//125
	print(a);
	system("pause");
	return 0;
}

