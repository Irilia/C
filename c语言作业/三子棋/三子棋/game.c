#define _CRT_SECURE_NO_WARNINGS 1
//�����ĳ�������
#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("****   1.play   0.exit   ****\n");
	printf("*****************************\n");
	printf("��ѡ��>");
}


void setboard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)//���̳�ʼ��Ϊ�ո�
	{
		for (j = 0; j < COL; j++)
		{
			arr[i][j] = ' ';
		}
		
	}
}

void displayboard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 1; i <= col; i++)
	{
		printf("  %d  ", i);
		if (i < COL )
			printf("|");
	}
	printf("\n");

	for (j = 0; j < COL ; j++)
	{
		if (j == 0)
		{
			printf(" ----");
		}
		else if (j > 0)
		{
			printf("-----");
		}
		if (j < COL - 1)
			printf("|");
	}
	printf("\n");
	
	for (i = 0; i < ROW; i++)
	{
		printf("%d ", i + 1);
		for(j = 0; j < COL; j++)
		{ 
			if (j == 0)
			{
				printf(" %c ", arr[i][j]);
			}
			else
			{
				printf("  %c  ", arr[i][j]);
			}
			
			if(j < COL - 1)
			   printf("|");
		}
		printf("\n");
		
		if(i < ROW-1)
		{ 
			for (j = 0; j < COL; j++)
			{
				if (j == 0)
				{
					printf(" ----");
				}
				else if (j > 0)
				{
					printf("-----");
				}
				if (j < COL - 1)
					printf("|");
			}
			printf("\n");
		}
		
		
	}

}

void playermove(char arr[ROW][COL], int row, int col)
{
	printf("\n\n����ߣ�>\n");
	while (1)
	{
		printf("���������꣺>");
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= ROW && y > 0 && y <= COL && arr[x-1][y-1] == ' ')
		{
			arr[x-1][y-1] = 'x';
			break;
		}
		else if (x > ROW || y > COL)
		{
			printf("�������꣬���������룡\n");
		}
		else if (arr[x-1][y-1] != ' ')
		{
			printf("�������¹����ˣ����������룡\n");
		}
		
	}
	
}

void computermove(char arr[ROW][COL], int row, int col)
{
	printf("\n\n�����ߣ�>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '0';
			break;
		}
	}
	
}

int  iswin(char arr[ROW][COL], int row, int col)
{
	int x = 0; 
	int y = 0;
	int count = 0;
	
	
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{

			if (arr[x][y] == arr[x][y - 1] && arr[x][y - 1] == arr[x][y + 1] && arr[x][y] != ' '&& arr[x][y-1] != ' '&& arr[x][y+1] != ' ')
			{
				return arr[x][y];
			}
			else if (arr[x][y] == arr[x - 1][y + 1] && arr[x - 1][y + 1] == arr[x + 1][y - 1] && arr[x][y] != ' '&& arr[x-1][y+1] != ' '&& arr[x+1][y-1] != ' ')
			{
				return arr[x][y];
			}
			else if(arr[x][y] == arr[x - 1][y] && arr[x - 1][y] == arr[x + 1][y] && arr[x][y] != ' '&& arr[x-1][y] != ' '&& arr[x+1][y] != ' ')
			{
				return arr[x][y];
			}
			else if (arr[x][y] == arr[x - 1][y - 1] && arr[x - 1][y - 1] == arr[x + 1][y + 1] && arr[x][y] != ' '&& arr[x-1][y-1] != ' '&& arr[x+1][y+1] != ' ')
			{
				return arr[x][y];
			}
		}
	}
}
int isfull(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (arr[x][y] == ' ')
				return 0;
		}
	}
	return 1;
}
		