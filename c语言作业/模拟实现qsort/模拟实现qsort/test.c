#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//void bubble_sort(int arr[], int sz)
//{
//	//冒泡：两两相邻的元素比较，第一个元素排完就不再排了，每趟排序少一个元素，从第一个排到最后一个元素为一趟
//	//拍到只剩一个元素使就不用再比较了，所以10个元素要排9趟
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)//多少趟9
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)//一趟排序,9,8,7,6,5,4,3,2,1,0
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	print_arr(arr,sz);
//	system("pause");
//	return 0;
//}

//模仿qsort的功能实现一个通用的冒泡排序
int cmp(const void*e1, const void*e2)
{
	return *(char*)e1 - *(char*)e2;
}

void Swap(char*buf1, char*buf2, size_t width)
{
	assert(buf1);
	assert(buf2);
	size_t i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *(buf1+i);
		*(buf1 + i) = *(buf2 + i);
		*(buf2 + i) = tmp;
	}
}

void my_qsort(void* base, size_t sz, size_t width, int (*cmp)(const void* e1, const void* e2))
{
	assert(base);
	size_t i = 0;
	for (i = 0; i < sz - 1; i++)//多少趟9
	{
		size_t j = 0;
		for (j = 0; j < sz - 1 - i; j++)//一趟排序,9,8,7,6,5,4,3,2,1,0
		{
			if (cmp((char*)base + (j*width), (char*)base + (j + 1)*width) > 0)
			{
				Swap((char*)base + (j*width), (char*)base + (j + 1)*width, width);
			}
		}
	}
}

void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[] = { 5,2,1,4,6,3,9,8,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr,sz,sizeof(arr[0]),cmp);
	print_arr(arr, sz);
	system("pause");
	return 0;
}