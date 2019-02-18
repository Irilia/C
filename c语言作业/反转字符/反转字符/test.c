#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[20][100];
	char b[20] = "student a am i";
	int i = 0;
	int j = 0;
	int e = 0;
	int f = 0;
	int n = 0;
	for (i = 0; b[i] != '\0'; i++)
	{
		n++;
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != ' ')
		{
			a[e][f] = b[i];
			f++;
		}
		else
		{

			a[e][f] = '\0';
			e++;
			f = 0;
		}
		if (i == n - 1)
		{
			a[e][f] = '\0';
			e++;

		}

	}
	a[e][0] = '\0';

	for (i = e - 1; i >= 0; i--)
	{
		printf("%s ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
