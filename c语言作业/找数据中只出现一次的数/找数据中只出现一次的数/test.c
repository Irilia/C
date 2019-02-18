#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int arr[11] = { 1, 1, 3, 6, 4, 4, 5, 5, 3 };
	int ret = 0;
	int size;
	size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		ret ^= arr[i];
	}
	printf("%d\n", ret);
	system("pause");
	return 0;
}
