#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Ժȶ�����ˮ��
//20+10+5+2+1+1=39

int main()
{
	int money = 20;
	int col = money;//����ٸ���ˮ
	int emp = col; //�ж��ٸ���ƿ
	while (emp > 1)
	{
		col += emp / 2;//��ƿ����ˮ
		emp = emp / 2 + emp % 2;
	}
	printf("%d", col);
	system("pause");
	return 0;
}