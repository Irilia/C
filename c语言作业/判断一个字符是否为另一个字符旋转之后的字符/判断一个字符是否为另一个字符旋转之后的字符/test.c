#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//void is_left(char*arr,char*arr1)
//{
//	int i = 0;
//	int a = 0;
//	int count = 0;
//	for (i = 1; i <+ 5; i++)
//	{
//		char tmp = *arr;
//		int j = 0;
//		while (*(arr + j + 1))
//		{
//			*(arr + j) = *(arr + j + 1);
//			for (a = 0; a < 5; a++)
//			{
//				if (*(arr + a) == *(arr1 + a))
//				{
//					count++;
//				}
//			}
//			if (count == 5)
//			{
//				printf("arr1是由arr左旋%d个字符得到的\n", i);
//			}
//			count = 0;
//			j++;
//		}
//		*(arr + j) = tmp;
//		
//		
//	}
//	
//}

void is_right(char*arr, char*arr1)
{
	int i = 0;
	int a = 0;
	int count = 0;
	for (i = 0; i < 5; i++)
	{
		char tmp = *(arr+5);
		int j = 5;
		while (j)
		{
			*(arr + j) = *(arr + j - 1);
			for (a = 0; a < 5; a++)
			{
				if (*(arr + a) == *(arr1 + a))
				{
					count++;
				}
			}
			if (count == 5)
			{
				printf("arr1是由arr右旋%d个字符得到的\n", i);
			}
			count = 0;
			j--;
		}
		*(arr) = tmp;
		
	}
}


int main()
{
	char arr[] = "ABCDEF";
	char arr1[5] = "0";
	int i = 0;
	scanf("%s", &arr1);
	/*is_left(arr,arr1);*/
	is_right(arr,arr1);
	system("pause");
	return 0;
}