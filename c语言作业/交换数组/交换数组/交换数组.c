#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5] = { 0 }, b[5] = { 0 };
	int i = 0;
	printf("������a��5������");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("������b��5������");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &b[i]);
	}
	for (i = 0; i < 5; i++)
	{
		a[i] = a[i] ^ b[i];
		b[i] = a[i] ^ b[i];
		a[i] = a[i] ^ b[i];
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d", b[i]);
	}
	system("pause");
	return 0;

}