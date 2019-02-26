#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//char* my_strchy(const char*dest, const char p)
//{
//	while (*dest)
//	{
//		if (*dest == p)
//		{
//			return (char*)dest;
//		}
//		dest++;
//	}
//	return NULL;
//}

char* my_strchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
	{
		++s;
	}
	return *s == c ? s : NULL;
}
int main()
{
	char str[] = "good boy";
	char p = 'o';
	char* ret = my_strchr(str, p);
	if (ret != NULL)
	{
		printf("%s\n", ret);
	}
	else
		printf("√ª’“µΩ\n");
	system("pause");
	return 0;
}