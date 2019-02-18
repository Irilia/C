#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void my_aver(int a,int b)
{
	printf("%d", a + (b - a) / 2);
}

int main()
{
	my_aver(2,3);
	system("pause");
	return 0;
}