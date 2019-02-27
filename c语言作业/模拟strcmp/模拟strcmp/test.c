#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int my_strcmp(const char*str1, const char*str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
int main()
{
	char* str1 = "abcdef";
	char* str2 = "abcdef";
	printf("%d ",my_strcmp(str1, str2));
	system("pause");
	return 0;
}