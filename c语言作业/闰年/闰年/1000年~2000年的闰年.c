//能被4整除，同时不能被100整除
//能被400整除
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if ((year % 4 == 0) &&(year % 100 != 0) || (year % 400 == 0))
		{
			printf("%d ", year);
		}
	}
	system("pause");
	return 0;
}
