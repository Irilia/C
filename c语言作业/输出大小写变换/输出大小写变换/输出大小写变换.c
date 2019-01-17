#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{	
	int a = '0';
	int tmp = 0;
	while(1)
	{  
		printf("请输入一个字母：");
		a = getchar();
		while ((tmp = getchar()) != '\n')
		{

		}
		if ((a >= 'A') && (a <= 'Z'))
	    {
		    a += 32;
			printf("%c\n", a);
	    }
	    else if ((a >= 'a') && (a <= 'z'))
	    {
		    a -= 32;
			printf("%c\n", a);
	    }
	    else
	    {
		    printf("不是字母，请重新输入\n");
	    }  
	}
	system("pause");
	return 0;
}