#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void test()
{
	Snake snake = { 0 };//创建贪吃蛇
	srand((unsigned int)time(NULL));
	GameStart(&snake);
	GameRun(&snake);
	GameOver(&snake);
}

//这是用来查看颜色对应编号的代码，可以给界面添加自己喜欢的颜色
void Test()
{
	//181淡蓝背景紫色
	//190淡蓝背景金色
	int i = 0;
	while (i < 600)
	{
		printf("%d ", color(i));
		i++;
	}
}

int main()
{
	test();
	//Test();
	system("pause");
	return 0;
}
