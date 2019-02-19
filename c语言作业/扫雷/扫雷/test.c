#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


int main()
{
	srand((unsigned int)time(NULL));
	int x = 0;
	//菜单
	while (1)
	{
		menu();
		printf("请选择:>");
		scanf("%d", &x);
		if (x == 1)
		{
			char mine[ROWS][COLS] = { 0 };//布置雷的棋盘11
			char show[ROWS][COLS] = { 0 };//查找雷的棋盘11
			//初始化
			setboard(mine, ROWS, COLS, '0');//设置雷的棋盘初始化11
			setboard(show, ROWS, COLS, '*');//设置排查的棋盘初始化11
			//打印
			displayboard(show, ROW, COL);//打印排查的棋盘9
			//布雷
			putmine(mine, ROW, COL);//9
			/*displayboard(mine, ROW, COL);*/
			
			//找雷
			findmine(mine,show, ROWS, COLS);
			
		}
		else if (x == 0)
		{
			printf("退出游戏！\n");
			break;
		}
		else
		{
			printf("输入错误，请重新输入！\n");
		}
	}
	





	system("pause");
	return 0;
}

