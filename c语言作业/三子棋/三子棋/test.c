#define _CRT_SECURE_NO_WARNINGS 1
//������������
#include "game.h"
int main()
{
	srand((unsigned int)time(NULL));
		//��Ϸ����
	
	int x = 0;
	int ret = 0;
	char n = 0;
	while(1)
	{
		menu();//�˵�
		scanf("%d", &x);
		printf("\n");
		if (x == 1)
		{
			//��������
			char arr[ROW][COL] = { 0 };
			setboard(arr, ROW, COL);//���̳�ʼ��Ϊ�ո�
			displayboard(arr, ROW, COL);//��ӡ����
			while (1)
			{
				//�������
				playermove(arr, ROW, COL);
				//��ӡ����
				displayboard(arr, ROW, COL);
				//�ж�ƽ��
				ret = isfull(arr, ROW, COL);
				if (ret == 1)
				{
					printf("ƽ��\n");
					break;
				}
				//�ж���Ӯ
				n = iswin(arr, ROW, COL);
				if (n == 'x')
				{
					printf("���Ӯ\n");
					break;
				}
				else if (n == '0')
				{
					printf("����Ӯ\n");
					break;
				}
				//���Ӯ--x
				//����Ӯ--0
				//ƽ��--P
				//����--C

				//��������
				computermove(arr, ROW, COL);
				//��ӡ����
				displayboard(arr, ROW, COL);
				//�ж�ƽ��
				ret = isfull(arr, ROW, COL);
				if (ret == 1)
				{
					printf("ƽ��\n");
					break;
				}
				//�ж���Ӯ
				n = iswin(arr, ROW, COL);
				if (n == 'x')
				{
					printf("���Ӯ\n");
					break;
				}
				else if (n == '0')
				{
					printf("����Ӯ\n");
					break;
				}
				
			}
			
		}	
		else if (x == 0)
			break;
		else
		printf("����������������룡\n");

	} 
	system("pause");
	return 0;
}