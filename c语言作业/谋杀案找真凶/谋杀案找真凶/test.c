#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()//四个人
{
	char arr[4] = { 'A','B','C','D' };
	//三个人说了真话，一个人说了假话,3+0=3；
	//a;不是a，b；是c；c：是d；d：c说胡话
	int a = 0;
	for (a = 0; a < 4; a++)//a=0
	{
		if (((arr[a] != 'A') + (arr[a] == 'C') + (arr[a] == 'D') +( arr[a] != 'D')) == 3)//1  2  3  2
		{
			printf("凶手是：%c\n", arr[a]);
		}
	}
	system("pause");
	return 0;
}