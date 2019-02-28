#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *p = "abcdef";
	int len = strlen(p);
	printf("%d\n", len);
	/*char *p = "abcdef";*/
	char *q = "abc";
	if(strlen(q)-strlen(p)>0)
	{
		printf("q>p\n");
	}
	else
	{
		printf("q<=p\n");
	}
	system("pause");
	return 0;
}