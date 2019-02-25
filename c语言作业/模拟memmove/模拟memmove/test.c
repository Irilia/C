#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void *my_memmove(void*dest, const void*src, size_t count)
{
	assert(dest);
	assert(src);

	void *ret = dest;

	if (dest <= src)
	{
		while (count--)
		{
			*(char *)dest = *(char *)src;
			((char *)dest)++;
			((char *)src)++;
		}
	}
	else
	{
		dest = (char *)dest + count - 1;
		src = (char *)src + count - 1;
		while (count--)
		{
			*(char *)dest = *(char *)src;
			((char *)dest)--;
			((char *)src)--;
		}
	}
	return ret;
}
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	my_memmove(a + 1, a + 4, 2*sizeof(int));
	int i = 0;
	int sz = sizeof(a) / sizeof(a[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}

//#include <stdio.h>
//#include <assert.h>
//
//void *MemMove(void *dest, const void *src, size_t count)
//{
//	assert(dest);
//	assert(src);
//
//	void *ret = dest;
//
//	if (dest <= src)
//	{
//		while (count--)
//		{
//			*(char *)dest = *(char *)src;
//			dest = (char *)dest + 1;
//			src = (char *)src + 1;
//		}
//	}
//	else
//	{
//		dest = (char *)dest + count - 1;
//		src = (char *)src + count - 1;
//		while (count--)
//		{
//			*(char *)dest = *(char *)src;
//			dest = (char *)dest - 1;
//			src = (char *)src - 1;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//	void * r = MemMove(arr + 1, arr+4, 4 * sizeof(int));
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
