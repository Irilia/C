#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void test()
{
	Snake snake = { 0 };//����̰����
	srand((unsigned int)time(NULL));
	GameStart(&snake);
	GameRun(&snake);
	GameOver(&snake);
}

//���������鿴��ɫ��Ӧ��ŵĴ��룬���Ը���������Լ�ϲ������ɫ
void Test()
{
	//181����������ɫ
	//190����������ɫ
	int i = 0;
	while (i < 600)
	{
		printf("%d ", color(i));
		i++;
	}
}

int main()
{
	test();
	//Test();
	system("pause");
	return 0;
}
