#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


int main()
{
	srand((unsigned int)time(NULL));
	int x = 0;
	//�˵�
	while (1)
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &x);
		if (x == 1)
		{
			char mine[ROWS][COLS] = { 0 };//�����׵�����11
			char show[ROWS][COLS] = { 0 };//�����׵�����11
			//��ʼ��
			setboard(mine, ROWS, COLS, '0');//�����׵����̳�ʼ��11
			setboard(show, ROWS, COLS, '*');//�����Ų�����̳�ʼ��11
			//��ӡ
			displayboard(show, ROW, COL);//��ӡ�Ų������9
			//����
			putmine(mine, ROW, COL);//9
			/*displayboard(mine, ROW, COL);*/
			
			//����
			findmine(mine,show, ROWS, COLS);
			
		}
		else if (x == 0)
		{
			printf("�˳���Ϸ��\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
		}
	}
	





	system("pause");
	return 0;
}

