#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()//�˵�
{
	printf("*****************************\n");
	printf("****   1.play   0.exit   ****\n");
	printf("*****************************\n");
}
void setboard(char board[ROWS][COLS], int rows, int cols, char n)//��ʼ����mine��ʼ��Ϊ0��show��ʼ��Ϊ*
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
void displayboard(char board[ROWS][COLS], int rows, int cols)//��ӡ����
{
	int x = 0;
	int y = 0;
	for (x = 0; x <= cols; x++)
	{
		printf("%d ", x);//��ӡ�е����
	}
	printf("\n");
	for (x = 1; x <= rows; x++)
	{
		printf("%d ", x);//��ӡ�е����
		for (y = 1; y <= cols; y++)
		{
			printf("%c ", board[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}
void putmine(char mine[ROWS][COLS], int rows, int cols)//���ף�ʹ��rand�������ֵ��srand��������������
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
//�������л��ж��ٸ�*��
//���������������Ƚ��жϣ�
//��*��������ʱ���׳ɹ�
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
		printf("������������꣺>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= rows && y > 0 && y <= cols && show[x][y] != ' ')//ע���ж�����Ϸ���
		{
			if (mine[x][y] == '1')
			{
				if (number(show) == ROW * COL)//��һ������ʱҪ�滻��λ��֤��Ҳ���first blood
				{
					firstsafe(mine, x, y);
					displayboard(mine, ROW, COL);//������ӡ���������λ��û�б��滻
					goto first;//�滻֮������жϸ����꣬ת��first
				}
				printf("YOU LOSE!GAME OVER!\n");//����Ҳ��ǵ�һ������ʱ������
				printf("\n");
				displayboard(mine, ROW, COL);//��ӡ��������ҿ����Լ��ȵ��ǲ�����
				break;
			}
			else
			{
				first:
				recfindmine(mine, show, x, y);//չ������
				displayboard(show, ROW, COL);
				displayboard(mine, ROW, COL);//�������
			}
		}
		else
		{
			printf("�����������������!\n");
		}
	}
	if (number(show) == low)//��*��������ʱ���׳ɹ�
	{
		printf("YOU WIN!\n");
		displayboard(mine, ROW, COL);
	}
}
//��һ��������Χ8����û����
//ע�����ͺ�ascii���ת����
//mine����ŵ����ַ�'0'��'1',
//��������������ֵ��
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
//����д��ʱ��д�Ĳ�����Χ8�����꣬���������������Χ4��Ҳ��һ����
//�õݹ��������ж�
//Ŀǰ�����������bug��չ����ʱ��������Χ���׵�ʱ�򲻻�ͣ��������ж�
//����չ�����������ģ�����ɨ�׿����ˡ������ǻ�����չ�����ܻ����ܹ�ʵ�ֵ�
//ϣ���������Ĵ��и�ָ��һ�£�лл��
void recfindmine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = minenum(mine, x, y);
	if (show[x][y] == '*' && i == 0)
	{
		show[x][y] = ' ';
		if (show[x - 1][y] == '*' && (x - 1) > 0 && y > 0)//��
		{
			recfindmine(mine, show, x-1, y);
		}
		//if ((x - 1) > 0 && (y - 1) > 0 && show[x - 1][y - 1] == '*')//����
		//{
		//	recfindmine(mine, show, x-1, y-1);
		//}
		//if ((x - 1) > 0 && (y + 1) > 0 && show[x - 1][y + 1] == '*')//����
		//{
		//	recfindmine(mine, show, x-1, y+1);
		//}
		if (show[x + 1][y] == '*' && (x + 1) > 0 && y > 0)//��
		{
			recfindmine(mine, show, x+1, y);
		}
		//if ((x + 1) > 0 && (y - 1) > 0 && show[x + 1][y - 1] == '*')//����
		//{
		//	recfindmine(mine, show, x+1, y-1);
		//}
		//if ((x + 1) > 0 && (y + 1) > 0 && show[x + 1][y + 1] == '*')//����
		//{
		//	recfindmine(mine, show, x+1, y+1);
		//}
		if (show[x][y + 1] == '*' && x > 0 && (y + 1) > 0)//��
		{
			recfindmine(mine, show, x, y+1);
		}
		if (show[x][y - 1] == '*' && x > 0 && (y - 1) > 0)//��
		{
			recfindmine(mine, show, x, y-1);
		}
	}
	else 
	{
		show[x][y] = i + '0';
	}
}
//��֤��һ���������ѵ�һ�������滻��0�����������һ�������׵�����ĳ���
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