#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c;
	for (a = 100; a < 201; a++)
	{
		c = 0;
		for (b = 2; b <= a; b++)
		{
			if (a%b == 0)
			{
				c++;
			}
		}
		if (c == 1)
			printf("%d ", a);
	}
	system("pause");
	return 0;
}

//int main()
//{
//	int i, j;
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2; j <= i-1 ; j++)
//		{
//			if (i%j == 0)
//				break;
//		}
//		if (j == i)
//			printf("%d ", i);
//	}
//	system("pause");
//	return 0;
//}