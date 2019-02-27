#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int a = 5;
//	int b = 0;
//	b = (a > 5 )?  3 : -3;
//	/*int a = -1;
//	int b = 0;
//	int *p = &a;
//	if (!b == 1)
//	{
//		printf("%d", sizeof (int));
//		b++;
////	}*/
//	printf("%d", b);
//	system("pause");
//	return 0;
//}
//字符串常量指针不能被修改
//int main()
//{
//	char *str = "abcdef";
//	*str = 'e';
//	printf("%s", str);
//	system("pause");
//	return 0;
//}
//char *arr[10];//一级字符指针数组
//char **arr1[10];//二级字符指针数组

#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	int *p = arr;
	int (*b)[10] = &arr;
	/*printf("%p\n", p);*/
	//printf("%p\n", &arr[1]);
	/*printf("%p\n", b);*/
	printf("%p\n", arr);
	printf("%p\n", &arr);

	system("pause");
	return 0;
}
