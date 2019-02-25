#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
int main()
{
	srand((unsigned int)time(NULL));
	int x = 0;
	while (1)
	{
		menu();//菜单
		printf("请选择:>");
		scanf("%d", &x);
		if (x == 1)
		{
			char mine[ROWS][COLS] = { 0 };//布置雷的棋盘
			char show[ROWS][COLS] = { 0 };//查找雷的棋盘
			//初始化
			setboard(mine, ROWS, COLS, '0');//设置雷的棋盘初始化
			setboard(show, ROWS, COLS, '*');//设置排查的棋盘初始化
			//打印
			displayboard(show, ROW, COL);//打印排查的棋盘9
			//布雷
			putmine(mine, ROW, COL);//
			displayboard(mine, ROW, COL);//打印用来方便测试
			//排雷
			findmine(mine,show, ROW, COL);
		}
		else if (x == 0)
		{
			printf("退出游戏！\n");
			break;
		}
		else
		{
			printf("输入错误，请重新输入！\n");//处理非法输入
		}
	}
	system("pause");
	return 0;
}

