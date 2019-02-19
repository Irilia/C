#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


void t_left( char* arr, int a )
{
	int i = 0;
	for (i = 0; i < a; i++)
	{
		char tmp = *arr;
		int j = 0;
		while (*(arr + j + 1))
		{
			*(arr + j) = *(arr + j + 1);
			j++;
		}
		*(arr + j) = tmp;
	}
	printf("%s", arr);
}


int main()
{
	char arr[] = "ABCDEF";//A放F后面‘/0’前面，AB
	int a = 0;
	scanf("%d", &a);
	t_left( arr, a );
	system("pause");
	return 0;
}