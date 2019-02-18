#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)//转二进制
{
	int count = 32;
	int arr[32] = { 0 };
	int b = 0;
	int i = 0;
	int num = 0;
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
		if (arr[i] == 1)
		{
			num++;
		}
	}
	printf("\n");
	return num;
}


int main()
{
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int ret = 0;
	scanf("%d", &a);
	scanf("%d", &b);
	ret = a ^ b;
	printf("%d ",count_one_bits(ret));
	system("pause");
	return 0;
}