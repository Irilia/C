#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()//�˵�
{
	printf("*****************************\n");
	printf("****   1.play   0.exit   ****\n");
	printf("*****************************\n");
}

void setboard(char board[ROWS][COLS], int rows, int cols,char n)//��ʼ��
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


void displayboard(char board[ROWS][COLS], int rows, int cols)//��ӡ
{
	int x = 0;
	int y = 0;
	for (x = 0; x <= cols; x++)
	{
		printf("%d ", x);
	}
	printf("\n");
	for (x = 1; x <= rows; x++)
	{
		printf("%d ", x);
		for (y = 1; y <= cols; y++)
		{
			printf("%c ", board[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}



void putmine(char mine[ROWS][COLS], int rows, int cols)//����
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

int residue(char show[ROWS][COLS])//�ݹ����������ʣ������������Ƿ���ͬ
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
	
	while (residue(show) != low)
	{
		printf("������������꣺>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= rows && y > 0 && y <= cols && show[x][y] != ' ')
		{
			if (mine[x][y] == '1')
			{
				if (residue(show) == ROW * COL)
				{
					firstsafe(mine, x, y);
					displayboard(mine, ROW, COL);
					goto first;
				}
				printf("YOU LOSE!GAME OVER!\n");
				printf("\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				first:
				recfindmine(mine, show, x, y);
				displayboard(show, ROW, COL);
			}
		
		}
		else
		{
			printf("�����������������!\n");
		}
	}
	if (residue(show) == low)
	{
		printf("YOU WIN!\n");
		displayboard(mine, ROW, COL);
	}
	
}


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


void recfindmine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0;
	i = minenum(mine,x, y);
	if (i == 0 && show[x][y] == '*')
	{
		show[x][y] = ' ';
		if ((x - 1) > 0 && y > 0 && show[x-1][y] == '*')//��
		{
			recfindmine(mine, show, x-1, y);
		}
		if ((x - 1) > 0 && (y - 1) > 0 && show[x - 1][y - 1] == '*')//����
		{
			recfindmine(mine, show, x-1, y-1);
		}
		if ((x - 1) > 0 && (y + 1) > 0 && show[x - 1][y + 1] == '*')//����
		{
			recfindmine(mine, show, x-1, y+1);
		}
		if ((x + 1) > 0 && y > 0 && show[x + 1][y] == '*')//��
		{
			recfindmine(mine, show, x+1, y);
		}
		if ((x + 1) > 0 && (y - 1) > 0 && show[x + 1][y - 1] == '*')//����
		{
			recfindmine(mine, show, x+1, y-1);
		}
		if ((x + 1) > 0 && (y + 1) > 0 && show[x + 1][y + 1] == '*')//����
		{
			recfindmine(mine, show, x+1, y+1);
		}
		if (x > 0 && (y + 1) > 0 && show[x][y + 1] == '*')//��
		{
			recfindmine(mine, show, x, y+1);
		}
		if (x > 0 && (y - 1) > 0 && show[x][y - 1] == '*')//��
		{
			recfindmine(mine, show, x, y-1);
		}
	}
	else 
	{
		show[x][y] = i + '0';
	}
}


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