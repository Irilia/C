#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char password[20] = {"0"};
	char cipher[] = { "123456" };
	int i = 0;
	int a = 0;
	int count = 0;
	printf("请输入密码：");
	scanf("%s", password);
	for(i=0;i<3;i++)
	{ 
		
	    if (a = strcmp(password, cipher)==0)
	    {
		printf("登陆成功！");
		break;
	    }
	    else if (a = strcmp(password, cipher)!=0)
	    {
		    count++;
			if (count == 3)
			{ 
				printf("三次输入错误，退出程序"); 
				break;
			}
			printf("输入错误，请重新输入密码：");
		    scanf("%s", password);
			
			
	    }
		
	}
	

	system("pause");
	return 0;
}