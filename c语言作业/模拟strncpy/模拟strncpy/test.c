#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char *my_strncpy(char *dest, const char *src, size_t count)
{
	char*ret = dest;
	while (count--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return ret;
}

int main()
{
	char arr[] = "abcdefg";
	char*p = "cdef";
	my_strncpy(arr, p, 3);
	printf("%s", arr);
	system("pause");
	return 0;
}