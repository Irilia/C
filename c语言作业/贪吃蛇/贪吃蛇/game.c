#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

int color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), x);
	return x;
}

void SetPos(int x, int y)
{
	COORD pos = { 0 };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void WelcomeToGame()
{
	//设置窗口大小
	system("mode con cols=100 lines=30");
	SetPos(45, 14);
	printf("欢迎来到贪吃蛇小游戏\n");
	SetPos(40, 28);
	system("pause");
	system("cls");
	SetPos(40, 13);
	printf("用↑，↓，←，→来控制蛇的移动，F1为加速。F2为减速。");
	SetPos(40, 14);
	printf("加速获得分数更多。");
	SetPos(40, 28);
	system("pause");
	system("cls");
}

void CreateMap()
{
	color(9);
	int i = 0;
	int j = 0;
	//上
	for (i = 0; i <= 58; i += 2)
	{
		SetPos(i, 0);
		printf(WALL);
	}
	//下
	for (i = 0; i <= 58; i += 2)
	{
		SetPos(i, 27);
		printf(WALL);
	}
	//左
	for (i = 1; i <= 26; i++)
	{
		SetPos(0, i);
		printf(WALL);
	}
	//右
	for (i = 1; i <= 26; i++)
	{
		SetPos(58, i);
		printf(WALL);
	}
	//中间背景
	color(11);
	for (i = 1; i <= 26; i++)
	{
		for (j = 2; j <= 56; j += 2)
		{
			SetPos(j, i);
			printf(WALL);
		}
	}
}
pSnakeNode BuyNode()
{
	pSnakeNode pRet = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pRet == NULL)
	{
		perror("BuyNode::malloc()");
		exit(EXIT_FAILURE);
	}
	pRet->x = 0;
	pRet->y = 0;
	pRet->next = NULL;
	return pRet;
}
void InitSnake(pSnake ps)
{
	color(181);
	pSnakeNode first = BuyNode();
	pSnakeNode cur = NULL;
	int i = 0;
	first->x = INIT_X;
	first->y = INIT_Y;

	for (i = 1; i <= 4; i++)
	{
		cur = BuyNode();
		cur->x = first->x + 2;
		cur->y = first->y;
		cur->next = first;
		first = cur;
	}
	//...
	/*while (cur)
	{
		SetPos(cur->x, cur->y);
		printf(FOOD);
		cur = cur->next;
	}*/
	SetPos(cur->x, cur->y);
	printf(SNAKEHEAD);
	while (cur->next)
	{
		SetPos(cur->next->x, cur->next->y);
		printf(SNAKE);
		cur = cur->next;
	}
	ps->_pSnake = first;
	SetPos(30, 13);
	//printf("\n");
}

void CreateFood(pSnake ps)
{
	color(181);
	pSnakeNode pFood = BuyNode();
	pSnakeNode cur = ps->_pSnake;
	pFood->y = rand() % 26 + 1;//1--26
	do
	{
		pFood->x = rand() % 55 + 2;//2--56
	} while (pFood->x % 2 != 0);
	//
	while (cur)
	{
		if (cur->x == pFood->x && cur->y == pFood->y)
		{
			CreateFood(ps);
			return;
		}
		cur = cur->next;
	}
	ps->_pFood = pFood;
	SetPos(pFood->x, pFood->y);
	printf(FOOD);
}

void GameStart(pSnake ps)
{
	//打印欢迎界面
	WelcomeToGame();
	//printf("%d\n", strlen("■"));
	//创建地图
	CreateMap();
	//初始化蛇
	InitSnake(ps);
	//初始化食物
	CreateFood(ps);
	//
	ps->_AddScore = 10;
	ps->_TotalScore = 0;
	ps->_Dir = RIGHT;
	ps->_SleepTime = 200;
	ps->_Status = OK;
}

void Pause()
{
	while (1)
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}
}

int NextHasFood(pSnakeNode pn, pSnakeNode pf)
{
	return ((pn->x == pf->x) && (pn->y == pf->y));
}

void EatFood(pSnake ps, pSnakeNode pn)
{
	color(181);
	pSnakeNode cur = NULL;
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;

	cur = ps->_pSnake;
	ps->_TotalScore += ps->_AddScore;
	SetPos(cur->x, cur->y);
	printf(SNAKEHEAD);
	while (cur->next)
	{
		SetPos(cur->next->x, cur->next->y);
		printf(SNAKE);
		cur = cur->next;
	}
	CreateFood(ps);
}

void NoFood(pSnake ps, pSnakeNode pn)
{
	color(181);
	pSnakeNode cur = NULL;
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;

	cur = ps->_pSnake;
	SetPos(cur->x, cur->y);
	printf(SNAKEHEAD);
	while (cur->next->next)
	{
		SetPos(cur->next->x, cur->next->y);
		printf(SNAKE);
		cur = cur->next;
	}
	SetPos(cur->next->x, cur->next->y);
	color(11);
	printf(WALL);
	free(cur->next);
	cur->next = NULL;
}

void SnakeMove(pSnake ps)
{
	pSnakeNode pNextNode = BuyNode();
	switch (ps->_Dir)
	{
	case UP:
	{
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		if (NextHasFood(pNextNode, ps->_pFood))
		{
			//下一个节点是食物
			EatFood(ps, pNextNode);
		}
		else
		{
			NoFood(ps, pNextNode);
		}
	}
	break;
	case DOWN:
	{
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		if (NextHasFood(pNextNode, ps->_pFood))
		{
			//下一个节点是食物
			EatFood(ps, pNextNode);
		}
		else
		{
			NoFood(ps, pNextNode);
		}
	}
	break;
	case LEFT:
	{
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		if (NextHasFood(pNextNode, ps->_pFood))
		{
			//下一个节点是食物
			EatFood(ps, pNextNode);
		}
		else
		{
			NoFood(ps, pNextNode);
		}
	}
	break;
	case RIGHT:
	{
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		if (NextHasFood(pNextNode, ps->_pFood))
		{
			//下一个节点是食物
			EatFood(ps, pNextNode);
		}
		else
		{
			NoFood(ps, pNextNode);
		}
	}
	break;
	}
}

void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 ||
		ps->_pSnake->x == 58 ||
		ps->_pSnake->y == 0 ||
		ps->_pSnake->y == 27)
	{
		ps->_Status = KILL_BY_WALL;
	}
}

void KillBySelf(pSnake ps)
{
	pSnakeNode pNext = ps->_pSnake->next;
	while (pNext)
	{
		if ((pNext->x == ps->_pSnake->x) && (pNext->y == ps->_pSnake->y))
		{
			ps->_Status = KILL_BY_SELF;
			return;
		}
		pNext = pNext->next;
	}
}

void PrintHelpInfo(pSnake ps)
{
	color(15);
	SetPos(65, 12);
	printf("用↑，↓，←，→来控制蛇的移动。");
	SetPos(65, 13);
	printf("按F1加速，按F2减速。\n");
	SetPos(65, 14);
	printf("按空格暂停，加速获得分数更多。\n");
	SetPos(65, 15);
	printf("按 Esc 退出游戏\n");
	SetPos(65, 8);
	printf("总分：%d ", ps->_TotalScore);
	SetPos(65, 9);
	printf("每个食物得分：%d ", ps->_AddScore);
}

void GameRun(pSnake ps)
{
	do
	{
		//确定方向
		PrintHelpInfo(ps);
		if (GetAsyncKeyState(VK_UP) && ps->_Dir != DOWN)
		{
			ps->_Dir = UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) && ps->_Dir != UP)
		{
			ps->_Dir = DOWN;
		}
		else if (GetAsyncKeyState(VK_LEFT) && ps->_Dir != RIGHT)
		{
			ps->_Dir = LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && ps->_Dir != LEFT)
		{
			ps->_Dir = RIGHT;
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			//暂停游戏
			Pause();
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			//结束游戏
			ps->_Status = NORMAL_END;
			break;
		}
		else if (GetAsyncKeyState(VK_F1))
		{
			//加速
			if (ps->_SleepTime >= 40)
			{
				ps->_SleepTime -= 20;
				ps->_AddScore += 2;
			}
		}
		else if (GetAsyncKeyState(VK_F2))
		{
			//减速
			if (ps->_SleepTime <= 300)
			{
				ps->_SleepTime += 20;
				ps->_AddScore -= 2;
			}
			if (ps->_SleepTime > 300)
			{
				ps->_AddScore = 1;
			}
		}
		Sleep(ps->_SleepTime);
		//蛇的移动
		SnakeMove(ps);
		KillByWall(ps);
		KillBySelf(ps);
	} while (ps->_Status == OK);
}

void GameOver(pSnake ps)
{
	color(15);
	pSnakeNode cur = ps->_pSnake;
	SetPos(26, 14);
	if (ps->_Status == NORMAL_END)
	{
		printf("正常结束游戏\n");
		SetPos(26, 16);
	}
	else if (ps->_Status == KILL_BY_SELF)
	{
		printf("自杀式死亡:(\n");
		SetPos(26, 16);
	}
	else if (ps->_Status == KILL_BY_WALL)
	{
		printf("撞墙!!!\n");
		SetPos(26, 16);
	}
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	ps->_pSnake = NULL;
	free(ps->_pFood);
	ps->_pFood = NULL;
}
