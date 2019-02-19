#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//1 5 10 10 5 1
//第一列j=0和对角线赋1（1.1）（2.2）（3.3）
//剩余值为其上两数相加之和arr[2][1]=arr[1][0]+arr[1][1]
int main()
{
	int arr[50][50];
	int i = 0; 
	int j = 0;
	int a = 0;
	scanf("%d", &a );
	for (i = 0; i < a; i++)                    
	{
		for (j = 0; j < a; j++)
		{
			if ((j == 0) || (i == j))
			{
				arr[i][j] = 1;

			}

		}

	}
	for (i = 0; i < a ; i++)               
	{
		for (j = 0; j < i; j++)
			{
				if (i > j && i > 1 && j > 0)
				{
					arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
				}
			}
		}
	for (i = 0; i < a; i++)              
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);

		}
		printf("\n");
	}
	system("pause");
	return 0;
}