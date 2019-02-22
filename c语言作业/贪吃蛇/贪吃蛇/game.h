#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _SNAKE_H__
#define _SNAKE_H__

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

enum Direction
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

enum GameStatus
{
	OK,
	NORMAL_END,
	KILL_BY_WALL,
	KILL_BY_SELF

};

#define WALL "■"
#define SNAKEHEAD "★"
#define SNAKE "●"
#define FOOD "◆"
#define INIT_X 20
#define INIT_Y 10

typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode *next;
}SnakeNode, *pSnakeNode;

typedef struct Snake
{
	pSnakeNode _pSnake;//维护蛇身的指针
	pSnakeNode _pFood;//维护食物的位置；
	int _TotalScore; //总分数；
	int _AddScore;  //增加的分数；
	int _SleepTime; //休眠时间；
	enum Direction _Dir;
	enum GameStatus _Status;

}Snake, *pSnake;

int color(int x);
void SetPos(int x, int y);
void WelcomeToGame();
void CreateMap();
pSnakeNode BuyNode();
void InitSnake(pSnake ps);
void CreateFood(pSnake ps);
void GameStart(pSnake ps);
void Pause();
int NextHasFood(pSnakeNode pn, pSnakeNode pf);
void EatFood(pSnake ps, pSnakeNode pn);
void NoFood(pSnake ps, pSnakeNode pn);
void SnakeMove(pSnake ps);
void KillByWall(pSnake ps);
void KillBySelf(pSnake ps);
void PrintHelpInfo(pSnake ps);
void GameRun(pSnake ps);
void GameOver(pSnake ps);

#endif //_SNAKE_H__

