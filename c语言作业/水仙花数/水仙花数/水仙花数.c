#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0, b = 0, c = 0;//a�ǰ�λ��b��ʮλ��c�Ǹ�λ��
	int sum = 0;
	int num = 0;
	int d, e, f;
	for (a = 1; a <= 9; a++)//ˮ�ɻ���Ϊ��λ����
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				num = a * 100 + b * 10 + c;
				d = a * a*a;
				e = b * b*b;
				f = c * c*c;
				sum = d + e + f;
				
				if (num == sum)
				{
					printf("%d ", sum);
				}
			}
		}

	}
	system("pause");
	return 0;
}