#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_prime(int a )
{
	int j = 0;
	for (j = 2; j <= sqrt(a); j++)
	{
		if (a%j == 0)
			return 0;
	}
	return 1;

}
int main()
{
	int i = 0;
	for(i=100;i<=200;i++)
	{ 

	   if (is_prime(i))
	   {
		   printf("%d ",i);
	   }
	}
	system("pause");
	return 0;
}