#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0, b = 0;
	for (a = 100; a < 201; a++)
	{
		for (b = 2; b <= a-1; b++)
		{
			if (a%b == 0)
				break;
			else
			{
				printf("%d ", a);
				break;
			}
		}

	}
	system("pause");
	return 0;
}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	for (b = 100; b <= 200; b++)
//	{
//		for ( c = 1; c < b-1; c++)
//		{
//			if (b%c == 0)
//				break;
//			
//		}
//		if (c == b)
//		{
//			printf("%d是一个素数",b);
//		}
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int i, j;
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2; j <= i - 1; j++)
//		{
//			if (i%j == 0)
//				break;
//		}
//		if (j == i)
//			printf("%d ", i);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}