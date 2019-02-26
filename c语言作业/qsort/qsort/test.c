#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  
#include<string.h>  


//int cmp1(const void * a, const void * b)    
//{
//	return (*(int*)a - *(int*)b);
//}
//
//int cmp2(const void * a, const void *b)
//{
//	return(*(char*)a - *(char*)b);
//}
//
//int cmp3(const void * a, const void *b)
//{
//	return(*(float*)a - *(float*)b);
//}
//
//int main(void)
//{
//	int i;
//	int a[10] = { 5,4,3,2,1,9,8,7,6,15 };
//	char b[10] = { 'v','s','z','e','q','d','y','w','u','a' };
//	float c[10] = { 0.125,0.135,6.213,4.216,8.469,0.236,19.364,5.648,9.563,14.25 };
//
//
//	qsort(a, 10, sizeof(int), &cmp1);//对于函数指针（指向函数的指针），直接传入函数名和函数名进行&  
//	//运算都是可以的，因为在调用函数时也是取的函数的地址  所以上下两种调用函数的方式都是可以的
//	qsort(b, 10, sizeof(char), cmp2);
//	qsort(c, 10, sizeof(float), cmp3);
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%c ", b[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%f ", c[i]);
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

//void qsort(void*base, size_t num, size_t width, int(__cdecl*compare)(const void*, const void*));

//{ 9, 1, 3, 2, 7, 5, 6, 4, 8, 0 }
//{ 'i', 'g', 'c', 'e', 'd', 'f', 'b', 'h', 'a', 'j' }
//{ 0.102,6.2,2.3,4.5,7.1,0.103,5.5,9.3,1.3,4.2 }

//
//int compare(const void * x, const void * y)
//{
//	return (*(int*)x - *(int*)y);
//}
//int compare1(const void * x, const void * y)
//{
//	return (*(char*)x - *(char*)y);
//}
//int compare2(const void * x, const void * y)
//{
//	return (*(float*)x - *(float*)y);
//}
//
//
//int main()
//{
//	int arr[10] = { 5,4,3,2,1,9,8,7,6,15 };
//	char arr1[10] = { 'v','s','z','e','q','d','y','w','u','a' };
//	float arr2[10] = { 0.125,0.135,6.213,4.216,8.469,0.236,19.364,5.648,9.563,14.25 };
//	qsort(arr, 10, sizeof(int), compare);
//	qsort(arr1, 10, sizeof(char), compare1);
//	qsort(arr2, 10, sizeof(float), compare2);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//		
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%c ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%f ", arr2[i]);
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}
int Add(x, y)
{
	return x + y;
}
int Sub(x, y)
{
	return x - y;
}
int Mul(x, y)
{
	return x * y;
}
int Div(x, y)
{
	return x / y;
}

void menu()
{
	printf("*************************************\n");
	printf("****      1.Add       2.Sub      ****\n");
	printf("****      3.Mul       4.Div      ****\n");
	printf("****            0.exit           ****\n");
	printf("*************************************\n");
}

void cale(int(*pf)(int,int))
{
	printf("请输入两个操作数：");
	int x = 0;
	int y = 0;
	scanf("%d%d", &x, &y);
	int ret = pf(x, y);
	printf("ret = %d", ret);
}
int main()
{
	int input = 0;
	int(*p[5])(int.int) = { 0,Add,Sub,Mul,Div };
	do
	{
		menu();
		printf("请选择：");
		calc(p[input]);

	}while(input)
	system("pause");
	return 0;
}

