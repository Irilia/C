#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define low 10
void menu();
void setboard(char board[ROWS][COLS], int rows, int cols,char n);
void displayboard(char board[ROWS][COLS], int rows, int cols);
void putmine(char mine[ROWS][COLS], int rows, int cols);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols);
void recfindmine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int minenum(char mine[ROWS][COLS], int x,int y);
int number(char show[ROWS][COLS]);
void firstsafe(char mine[ROWS][COLS], int x, int y);