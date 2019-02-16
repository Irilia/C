#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int count_one_bits(unsigned int value)
{
	int count = 32;
	int arr[32] = { 0 };
	int b = 0;
	int i = 0;
	int num = 0;
	while (count != 0)
	{
		b = value % 2;
		if (b == 1)
		{
			num++;
		}
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
	return num;
}
int main()
{
	unsigned int a = 0;
	scanf("%d", &a);
	printf("%d", count_one_bits(a));
	system("pause");
	return 0;
}

