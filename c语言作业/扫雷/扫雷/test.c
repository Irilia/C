#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
int main()
{
	srand((unsigned int)time(NULL));
	int x = 0;
	while (1)
	{
		menu();//�˵�
		printf("��ѡ��:>");
		scanf("%d", &x);
		if (x == 1)
		{
			char mine[ROWS][COLS] = { 0 };//�����׵�����
			char show[ROWS][COLS] = { 0 };//�����׵�����
			//��ʼ��
			setboard(mine, ROWS, COLS, '0');//�����׵����̳�ʼ��
			setboard(show, ROWS, COLS, '*');//�����Ų�����̳�ʼ��
			//��ӡ
			displayboard(show, ROW, COL);//��ӡ�Ų������9
			//����
			putmine(mine, ROW, COL);//
			displayboard(mine, ROW, COL);//��ӡ�����������
			//����
			findmine(mine,show, ROW, COL);
		}
		else if (x == 0)
		{
			printf("�˳���Ϸ��\n");
			break;
		}
		else
		{
			printf("����������������룡\n");//����Ƿ�����
		}
	}
	system("pause");
	return 0;
}

