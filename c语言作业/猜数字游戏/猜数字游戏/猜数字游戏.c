#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int game()
{
	int i = 0;
	int guess = 0;
	scanf("%d", &guess);
	i = rand() % 100 + 1;
	do{
		if (guess < i)
		{
			printf("̫С��,�����²�һ������");
			scanf("%d", &guess);
		}
		else if (guess > i)
		{
			printf("̫����,�����²�һ������");
			scanf("%d", &guess);
		}
		else
		{
			printf("��ϲ��¶��ˣ�\n");
			break;
		}
	} while (1);
	return 0;
}


int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	while (1)
	{
		printf("***      ������Ϸ     ***\n");
		printf("**************************\n");
		printf("**** 1.play    0.exit ****\n");
		printf("**************************\n");
		printf("��ѡ��");
		scanf("%d",&a);
		if (a == 1)
		{

			//����һ�������
			printf("���һ������");
			
			game();
			

		}
		else if (a == 0)
		{
			printf("�˳���Ϸ\n");
			break;
		}
		else
			printf("ѡ�����������ѡ��");
	}

	system("pause");
	return 0;
}