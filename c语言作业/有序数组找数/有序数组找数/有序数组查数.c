#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	
	
	int k = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
    int left = 0;
	int i = 0;
	int mid = left + (right - left) / 2;
	printf("请输入你想找的数：");
	scanf("%d",&k);
	while (left <= right)
	{
		if (k > arr[mid])
		{
			left = mid+1;
		}
		else if (k < arr[mid])
		{
			right = mid-1;
		}
		else
		{
			printf("找到了，下标是%d", mid);
			break;
		}
		mid = left + (right - left) / 2;
	}
	if (left > right)
	{
		printf("-1");
	}
	system("pause");
	return 0;
}