#define _CRT_SECURE_NO_WARNINGS 1
//模拟实现strcpy,复制字符串
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//char *strcpy(char *strDestination, const char *strSource);

//int my_strlen(const char*arr)
//{
//	int count = 0;
//	while (*arr !='\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}

char *my_strcpy(char*arr1, const char*arr)
{
	char*p = arr1;
	while(*arr!='\0')
	{
		*arr1 = *arr;
		arr++;
		arr1++;
	}
	*arr1 = *arr;
	return p;
}

//char *my_strcpy(char*arr1, const char*arr)
//{
//	char* p= arr1;
//	assert(arr1);
//	assert(arr);
//	while (*arr1++ = *arr++)
//	{
//		;
//	}
//	return p;
//}


int main()
{
	const char arr[] = "abcdef";
	char arr1[] = "0";
	printf("arr1=%s\n", arr1);
	my_strcpy(arr1, arr);
	printf("arr1=%s\n", arr1);
	system("pause");
	return 0;
}