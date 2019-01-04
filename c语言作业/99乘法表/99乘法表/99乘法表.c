#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0, b = 0, c = 0;
	for (a = 1; a < 10; a++)
	{
		for (b = 1; b <= a; b++)
		{
			c = a * b;
			printf("%d*%d=%d ", b, a, c);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}