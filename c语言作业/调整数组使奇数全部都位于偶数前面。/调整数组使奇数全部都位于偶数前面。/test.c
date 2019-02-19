#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void change(int (*p)[10],int sz)//p是数组指针
{
	int i = 0;
	int j = 4;
	int arr1[10] = { 0 };
	for (i = 0; i < sz; i++)
	{
		if ((i + 1) % 2 != 0)//0，1，2，3，4
		{
			arr1[i - i / 2] = *(*p + i);//0-0，2-1，4-2，6-3，8-4，10-5
		}
		else
		{
			arr1[i + j] = *(*p + i);//1-5，3-6，5-7，7-8，9-9
			j--;
		}
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	change(&arr,sz);
	system("pause");
	return 0;
}