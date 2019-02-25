#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

const char *my_strstr(const char*str1, const char*str2)
{
	assert(str1);
	assert(str2);
	const char *cp = str1;
	const char *sr = str2;
	while (*cp)
	{
		str1 = cp;
		str2 = sr;
		while (*str1 && *str2 && (*str1 == *str2))
		{
			str1++;
			str2++;
		}
		if (*str1 == '\0')
		{
			return NULL;
		}
		if (*str2 == '\0')
		{
			return cp;
		}
		cp++;
	}
}

int main()
{
	const char str1[] = "abbbbcdefabcd";
	const char str2[] = "bbc";
	printf("%s\n",my_strstr(str1,str2));
	system("pause");
	return 0;
}

