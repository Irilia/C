#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//strcat(a,b),将b连接到a后，无空格连接
//void main(void)
//{
//	char string[80];
//	strcpy(string, "Hello world from ");
//	strcat(string, "strcpy ");
//	strcat(string, "and ");
//	strcat(string, "strcat!");
//	printf("String = %s\n", string);
//	system("pause");
//}

//char *strcat(char *strDestination, const char *strSource);



char *my_strcat(char *arr, const char *arr1)
{
	int ret1 = strlen(arr1);
	int i = 0;
	for (i = 0; i < ret1; i++)
	{
		int ret = strlen(arr);
		*(arr + ret) = *arr1;
		arr1++;
		
	}
	return 0;
}

int main()
{
	char arr[80] = "Hello ";
	char arr1[] = "everbody ";
	my_strcat(arr, arr1);
	printf("%s", arr);
	system("pause");
	return 0;
}
