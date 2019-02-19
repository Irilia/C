#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int change(int *px, int *py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
	return 0;
}
int main()
{
	int a = 0, b = 0;
	scanf("%d %d",&a,&b);
	change(&a,&b);
	printf("a = %d,b = %d", a, b);
	system("pause");
	return 0;
}