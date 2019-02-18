#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int power(int j)
//{
//	if (j < 1)
//		return 1;
//	else
//	{
//		return 2 * power(j - 1);
//	}
//}

void reverse_bit(unsigned int value)
{
	int i = 0;
	char arr[32];
	int j = 0, sum = 0, t = 0;
	for (i = 32; i >= 1; i--)
	{
		printf("%d", value & 1);
		arr[j++] = (value & 1);
		value = value >> 1;
	}
	/*printf("\n");
	j = 0;
	for (i = 31; i >= 0; i--)
	{
		if (arr[i] == 1)
			{
				t = power(j);
			}
		j++;
		sum += t;
	}
	printf("%d", sum);
	*/
}


int main()
{
	unsigned int a = 0;
	scanf("%d", &a);
	reverse_bit(a);
	system("pause");
	return 0;
}