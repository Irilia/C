#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void init(int *px)//init（）初始化数组、
{
	scanf("%d", px);
}
int empty(int *px)/*empty（）清空数组*/
{
	return *px = (*px) & 0;
}
void reverse(int *px,int sz,int i)/*reverse（）函数完成数组元素的逆置*/
{
	int temp = 0;
	temp = *(px);//*px=1=temp
	*px = *(px + sz - 1-2*i);
	*(px + sz - 1 -2*i) = temp;
}


int main()
{
	int arr[5] = {1,2,3,4,5};
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[1]);
	printf("\narr[5] = ");
	
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	
	for (i = 0; i < 5; i++)
	{
		init(&arr[i]);
	}
	
	printf("\narr[5] = ");

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\narr[5] = ");
	for (i = 0; i < 5; i++)
	{
		empty(&arr[i]);
		printf("%d ", arr[i]);
	}

	printf("\narr[5] = ");

	for (i = 0;i<sz/2;i++)
	{
		reverse(&arr[i],sz, i);
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}