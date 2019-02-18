#define _CRT_SECURE_NO_WARNINGS 1
//函数声明
//变量定义
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9


void setboard(char arr[ROW][COL], int row, int col);
void displayboard(char arr[ROW][COL], int row, int col);
void playermove(char arr[ROW][COL], int row, int col);
void computermove(char arr[ROW][COL], int row, int col);
int iswin(char arr[ROW][COL], int row, int col);
int isfull(char arr[ROW][COL], int row, int col);
void menu();