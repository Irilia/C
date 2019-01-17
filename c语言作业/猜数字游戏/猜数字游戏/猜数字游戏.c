#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int game()
{
	int i = 0;
	int guess = 0;
	scanf("%d", &guess);
	i = rand() % 100 + 1;
	do{
		if (guess < i)
		{
			printf("太小了,请重新猜一个数：");
			scanf("%d", &guess);
		}
		else if (guess > i)
		{
			printf("太大了,请重新猜一个数：");
			scanf("%d", &guess);
		}
		else
		{
			printf("恭喜你猜对了！\n");
			break;
		}
	} while (1);
	return 0;
}


int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	while (1)
	{
		printf("***      猜字游戏     ***\n");
		printf("**************************\n");
		printf("**** 1.play    0.exit ****\n");
		printf("**************************\n");
		printf("请选择：");
		scanf("%d",&a);
		if (a == 1)
		{

			//给出一个随机数
			printf("请猜一个数：");
			
			game();
			

		}
		else if (a == 0)
		{
			printf("退出游戏\n");
			break;
		}
		else
			printf("选择错误，请重新选择！");
	}

	system("pause");
	return 0;
}