#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()//五个选手
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	//每个选手都有5种名次可能
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((b == 2) + (a == 3) == 1 && (b == 2) + (e == 4) == 1 && (c == 1) + (d == 2) == 1 && (d == 3) + (c == 5) == 1 && (a == 1) + (e == 4) == 1)
						{
								if (120 == a * b*c*d*e)
								{
									printf("A=%d B=%d C=%d D=%d E=%d\n", a, b, c, d, e);
								}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}