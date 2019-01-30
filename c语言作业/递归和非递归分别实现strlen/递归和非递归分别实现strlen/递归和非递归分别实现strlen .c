#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//int my_strlen(char* n)
//{
//	if (*n != '\0')
//	{
//		return 1 + my_strlen(n + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()//µÝ¹é
//{
//	char* p = "abcdefg";
//	printf("%d", my_strlen(p));
//	system("pause");
//	return 0;
//}


int main()//·ÇµÝ¹é
{
	char arr[] = "abcdefg";
	printf("%d",strlen(arr));
	system("pause");
	return 0;
}