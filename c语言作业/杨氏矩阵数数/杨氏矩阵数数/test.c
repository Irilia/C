#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void find(int(*p)[3], int x, int y, int a)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (*(*(p + i)+j) == a)
			{
				printf("����λ��Ϊ��%d,%d", i, j);
				count++;
			}
		}
		
	}
	if (count == 0)
	{
		printf("û�������\n");
	}
}
int main()
{
	int a = 0;
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	scanf("%d", &a);
	find(arr, 3, 3, a);
	system("pause");
	return 0;
}