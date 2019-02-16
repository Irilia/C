#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int power_function(int a, int b)//µÝ¹é
//{
//	if (b == 0)
//	{
//		return 1;
//	}
//	else if (b == 1)
//	{
//		return a;
//	}
//	else 
//	{
//		return a*power_function(a,b-1);
//	}
//	
//}


int power_function(int a,int b)//·ÇµÝ¹é
{
	int i = 0;
	int c = 1;
	for (i = 0; i < b; i++)
	{
		c = c * a;
	}
	return c;

}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d",&n,&k);
	printf("%d",power_function(n,k));
	system("pause");
	return 0;
}