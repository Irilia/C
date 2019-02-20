#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void count_one_bits(unsigned int value)//转二进制
{
	int count = 32;
	int arr[32] = { 0 };
	int b = 0;
	int i = 0;
	while (count != 0)
	{
		b = value % 2;
		arr[i] = b;//0-32
		i++;
		value = value / 2;
		count--;
	}
	for (i = 31; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("偶数位：");
	for (i = 31; i >= 1; i-=2)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("奇数位：");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	unsigned int value = 0;
	scanf("%d", &value);
	count_one_bits(value);
	system("pause");
	return 0;
}