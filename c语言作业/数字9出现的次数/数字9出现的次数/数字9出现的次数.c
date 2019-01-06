#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int b = 0;
	int c = 0;
	int count = 0;//1-100有三位数，a，b，c；a=1，b=0-9，c=0-9；
	for (b = 0; b <= 9; b++)
	{
		for (c = 0; c <= 9; c++)
		{
			int sum = b*10+c;
			if ((c==9)|| (b == 9))//19,29,39..99%10==9;90/9==10,
			{
				count++;
				if ((c == 9) && (b == 9))
				{
					count++;
				}
			    printf("%d ", sum);
			}
		}
	}
	printf("\n1-100中出现了%d次的9\n", count);
	system("pause");
	return 0; 
}