#define _CRT_SECURE_NO_WARNINGS 1
//三子棋主函数
#include "game.h"
int main()
{
	srand((unsigned int)time(NULL));
		//游戏界面
	
	int x = 0;
	int ret = 0;
	char n = 0;
	while(1)
	{
		menu();//菜单
		scanf("%d", &x);
		printf("\n");
		if (x == 1)
		{
			//设置棋盘
			char arr[ROW][COL] = { 0 };
			setboard(arr, ROW, COL);//棋盘初始化为空格
			displayboard(arr, ROW, COL);//打印棋盘
			while (1)
			{
				//玩家下棋
				playermove(arr, ROW, COL);
				//打印棋盘
				displayboard(arr, ROW, COL);
				//判断平局
				ret = isfull(arr, ROW, COL);
				if (ret == 1)
				{
					printf("平局\n");
					break;
				}
				//判断输赢
				n = iswin(arr, ROW, COL);
				if (n == 'x')
				{
					printf("玩家赢\n");
					break;
				}
				else if (n == '0')
				{
					printf("电脑赢\n");
					break;
				}
				//玩家赢--x
				//电脑赢--0
				//平局--P
				//继续--C

				//电脑下棋
				computermove(arr, ROW, COL);
				//打印棋盘
				displayboard(arr, ROW, COL);
				//判断平局
				ret = isfull(arr, ROW, COL);
				if (ret == 1)
				{
					printf("平局\n");
					break;
				}
				//判断输赢
				n = iswin(arr, ROW, COL);
				if (n == 'x')
				{
					printf("玩家赢\n");
					break;
				}
				else if (n == '0')
				{
					printf("电脑赢\n");
					break;
				}
				
			}
			
		}	
		else if (x == 0)
			break;
		else
		printf("输入错误，请重新输入！\n");

	} 
	system("pause");
	return 0;
}