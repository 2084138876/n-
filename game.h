#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



#define ROW 5
#define COL 5

void InitBoard(char board[ROW][COL], int row, int col);// ��ʼ������,����ÿ�����Ӹ�ֵ


void DispalyBoard(char board[ROW][COL], int row, int col);// ��ʾ����ӡ����

void PlayerMove(char board[ROW][COL], int row, int col);//�������

void ComputerMove(char board[ROW][COL],int row ,int col);//��������

char IsWin(char board[ROW][COL], int row, int col);//�ж���Ӯ

void IsWho(char ret);