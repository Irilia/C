#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//void *memcpy(void *dest, const void *src, size_t count);

void my_memcpy(void*dest, const void*src, size_t count)
{
	assert(dest);
	assert(src);
	while (count)
	{
		*(int*)dest = *(int *)src;
		((int*)dest)++;
		((int*)src)++;
		count--;
	}
}

int main()
{
	int a[] = { 1,2,3,4,5,6,7 };
	int b[] = { 1,2,3,4 };
	int sz = sizeof(a) / sizeof(a[0]);
	my_memcpy(a+2, b, 2);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}