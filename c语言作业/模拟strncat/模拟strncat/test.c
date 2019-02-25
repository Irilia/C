#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* my_strncpy(char*dest, const char*src, size_t count)
{
	assert(dest);
	assert(src);
	char*ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (count&&*src)
	{
		*dest++ = *src++;
		count--;
	}
	*dest = 0;
	return ret;
}
int main()
{
	char a[50] = "hello ";
	char *p = "world";
	printf("%s", my_strncpy(a, p, 5));
	system("pause");
	return 0;
}

