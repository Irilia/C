#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()//菜单
{
	printf("*****************************\n");
	printf("****   1.play   0.exit   ****\n");
	printf("*****************************\n");
}
void setboard(char board[ROWS][COLS], int rows, int cols, char n)//初始化，mine初始化为0，show初始化为*
{
	int x = 0;
	int y = 0;
	int a = 0;
	for (x = 0; x < rows; x++)
	{
		for (y = 0; y < cols; y++)
		{
			board[x][y] = n;
		}
	}
}
void displayboard(char board[ROWS][COLS], int rows, int cols)//打印棋盘
{
	int x = 0;
	int y = 0;
	for (x = 0; x <= cols; x++)
	{
		printf("%d ", x);//打印列的序号
	}
	printf("\n");
	for (x = 1; x <= rows; x++)
	{
		printf("%d ", x);//打印行的序号
		for (y = 1; y <= cols; y++)
		{
			printf("%c ", board[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}
void putmine(char mine[ROWS][COLS], int rows, int cols)//布雷，使用rand产生随机值，srand调用在主函数里
{
	int x = 0;
	int y = 0;
	int count = low;
	while (count)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
//计算盘中还有多少个*，
//后面用来和雷数比较判断，
//当*等于雷数时排雷成功
int number(char show[ROWS][COLS])
{
	int count = 0;
	int x = 0;
	int y = 0;
	for (x = 1; x <= ROW; x++)
	{
		for (y = 1; y <= COL; y++)
		{
			if (show[x][y] == '*')
				count++;
		}
	}
	return count;
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
	int x = 0;
	int y = 0;
	
	while (number(show) != low)
	{
		printf("请输入查找坐标：>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= rows && y > 0 && y <= cols && show[x][y] != ' ')//注意判断坐标合法性
		{
			if (mine[x][y] == '1')
			{
				if (number(show) == ROW * COL)//第一步踩雷时要替换雷位保证玩家不会first blood
				{
					firstsafe(mine, x, y);
					displayboard(mine, ROW, COL);//用来打印方便测试雷位有没有被替换
					goto first;//替换之后继续判断该坐标，转到first
				}
				printf("YOU LOSE!GAME OVER!\n");//当玩家不是第一步踩雷时就输了
				printf("\n");
				displayboard(mine, ROW, COL);//打印雷盘让玩家看到自己踩得是不是雷
				break;
			}
			else
			{
				first:
				recfindmine(mine, show, x, y);//展开程序
				displayboard(show, ROW, COL);
				displayboard(mine, ROW, COL);//方便测试
			}
		}
		else
		{
			printf("坐标错误，请重新输入!\n");
		}
	}
	if (number(show) == low)//当*等于雷数时排雷成功
	{
		printf("YOU WIN!\n");
		displayboard(mine, ROW, COL);
	}
}
//算一个坐标周围8个有没有雷
//注意整型和ascii码的转换，
//mine盘里放的是字符'0'和'1',
//函数返回是整型值，
//'1'-'0'=1;
int minenum(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
//本来写的时候写的查找周围8个坐标，结果后来发现找周围4个也是一样的
//用递归来进行判断
//目前这个函数还有bug，展开有时候遇到周围有雷的时候不会停，会继续判断
//导致展开不是连续的，就像扫雷开挂了。。但是基本的展开功能还是能够实现的
//希望看出来的大佬给指点一下，谢谢；
void recfindmine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = minenum(mine, x, y);
	if (show[x][y] == '*' && i == 0)
	{
		show[x][y] = ' ';
		if (show[x - 1][y] == '*' && (x - 1) > 0 && y > 0)//上
		{
			recfindmine(mine, show, x-1, y);
		}
		//if ((x - 1) > 0 && (y - 1) > 0 && show[x - 1][y - 1] == '*')//左上
		//{
		//	recfindmine(mine, show, x-1, y-1);
		//}
		//if ((x - 1) > 0 && (y + 1) > 0 && show[x - 1][y + 1] == '*')//右上
		//{
		//	recfindmine(mine, show, x-1, y+1);
		//}
		if (show[x + 1][y] == '*' && (x + 1) > 0 && y > 0)//下
		{
			recfindmine(mine, show, x+1, y);
		}
		//if ((x + 1) > 0 && (y - 1) > 0 && show[x + 1][y - 1] == '*')//左下
		//{
		//	recfindmine(mine, show, x+1, y-1);
		//}
		//if ((x + 1) > 0 && (y + 1) > 0 && show[x + 1][y + 1] == '*')//右下
		//{
		//	recfindmine(mine, show, x+1, y+1);
		//}
		if (show[x][y + 1] == '*' && x > 0 && (y + 1) > 0)//右
		{
			recfindmine(mine, show, x, y+1);
		}
		if (show[x][y - 1] == '*' && x > 0 && (y - 1) > 0)//左
		{
			recfindmine(mine, show, x, y-1);
		}
	}
	else 
	{
		show[x][y] = i + '0';
	}
}
//保证第一步不死，把第一步的雷替换成0，再随机生成一个不是雷的坐标改成雷
void firstsafe(char mine[ROWS][COLS], int x, int y)
{
	mine[x][y] = '0';
	while (1)
	{
		int a = 0;
		int b = 0;
		a = rand() % ROW + 1;
		b = rand() % COL + 1;
		if (mine[a][b] == '0')
		{
			mine[a][b] = '1';
			break;
		}
	}
}