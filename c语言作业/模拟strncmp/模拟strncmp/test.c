#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int my_strncmp(const char*dest, const char*src, size_t count)
{
	assert(dest);
	assert(src);
	while (--count)
	{
		if (*dest == *src)
		{
			if (*dest == 0)
			{
				return 0;
			}
			dest++;
			src++;
		}
	}
	return *dest - *src;
}

int main()
{
	char a[] = "abcdhfg";
	char*p = "abcef";
	printf("%d",my_strncmp(a,p,3));
	system("pause");
	return 0;
}

