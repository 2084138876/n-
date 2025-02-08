#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



#define ROW 5
#define COL 5

void InitBoard(char board[ROW][COL], int row, int col);// 初始化棋盘,即给每个格子赋值


void DispalyBoard(char board[ROW][COL], int row, int col);// 显示、打印棋盘

void PlayerMove(char board[ROW][COL], int row, int col);//玩家下棋

void ComputerMove(char board[ROW][COL],int row ,int col);//电脑下棋

char IsWin(char board[ROW][COL], int row, int col);//判断输赢

void IsWho(char ret);