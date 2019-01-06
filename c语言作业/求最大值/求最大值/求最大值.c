#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[9];
	int i = 0;
	printf("请输入10个数：");
	for (i = 0; i <10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max = arr[0];
	for (i = 1; i<10;i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	printf("最大值是%d", max);
	
	system("pause");
	return 0;
}
//5124897
//5-1>0--5-2>0--5-4>0---5-8<0--