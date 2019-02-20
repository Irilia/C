#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以喝多少汽水。
//20+10+5+2+1+1=39

int main()
{
	int money = 20;
	int col = money;//买多少个汽水
	int emp = col; //有多少个空瓶
	while (emp > 1)
	{
		col += emp / 2;//空瓶换汽水
		emp = emp / 2 + emp % 2;
	}
	printf("%d", col);
	system("pause");
	return 0;
}