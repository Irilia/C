#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


//有临时变量的交换两个数
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	printf("请输入两个数进行交换:");
//	scanf("%d%d", &a, &b);
//	printf("a=%d,b=%d", a, b);
//	c = a;
//	a = b;
//	b = c;
//	printf("\na=%d,b=%d", a, b);
//	system("pause");
//	return 0;
//}


//不允许创建临时变量，交换两个数
//int main()
//{
//	int a = 0, b = 0;
//	printf("请输入两个数：");
//	scanf("%d %d", &a, &b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("%d,%d", a, b);
//	system("pause");
//	return 0;
//}

int main()
{
	int a = 0, b = 0;
	printf("请输入两个数：");//10-01010,20-10100
	scanf("%d %d", &a, &b);
	a = a ^ b;//11110
	b = a ^ b;//01010
	a = a ^ b;//10100
	printf("%d,%d", a, b);
	system("pause");
	return 0;

}

