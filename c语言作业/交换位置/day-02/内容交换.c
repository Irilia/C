#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


//����ʱ�����Ľ���������
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	printf("���������������н���:");
//	scanf("%d%d", &a, &b);
//	printf("a=%d,b=%d", a, b);
//	c = a;
//	a = b;
//	b = c;
//	printf("\na=%d,b=%d", a, b);
//	system("pause");
//	return 0;
//}


//����������ʱ����������������
//int main()
//{
//	int a = 0, b = 0;
//	printf("��������������");
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
	printf("��������������");//10-01010,20-10100
	scanf("%d %d", &a, &b);
	a = a ^ b;//11110
	b = a ^ b;//01010
	a = a ^ b;//10100
	printf("%d,%d", a, b);
	system("pause");
	return 0;

}

