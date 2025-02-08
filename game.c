#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <string.h>

void InitBoard(char board[ROW][COL], int row, int col)//初始化棋盘,即给每个格子赋值
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] =' ';
		}
	}
}

void DispalyBoard(char board[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0;
	int j = 0;
	int k = 0;
	//打印3x3 的棋盘
	/*for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf(" %c ", board[i][j]);
			if (j<2)
				printf("|");
		}
		printf("\n");
		if (i<2)
			printf("---+---+---\n");
	}*/

	//打印ROW * COL 的棋盘
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
				printf("|");
		}
		printf("\n");
		if (i < ROW - 1)
			for (k = 0; k < COL; k++)
			{
				printf("---");
				if (k < COL - 1)
					printf("+");
			}
		printf("\n");
	}
}



void PlayerMove(char board[ROW][COL], int row, int col)//玩家下棋
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家下棋\n");
		printf("请输入坐标: >");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)//判断输入的坐标是否在棋盘范围内
		{
			if (board[x - 1][y - 1] == ' ')//判断玩家输入的坐标是否已经存在棋子
			{
				board[x - 1][y - 1] = '*';//玩家下棋用*表示
				break;
			}
			else
			{
				printf("该坐标已有棋子,请重新输入！\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}



void ComputerMove(char board[ROW][COL], int row, int col)//电脑下棋   电脑随机下棋
{
	
	while (1)
	{
		int x = rand() % ROW;//rand()函数产生随机数的范围是0~65535，模上ROW后值是0~ROW-1
		int y = rand() % COL;//rand()函数使用前需要先使用srand()函数设置随机起点
		//此时 x和y的范围都在棋盘范围内
		if (board[x][y] == ' ')//判断随机坐标是否有棋子
		{
			board[x][y] = '#';
			printf("电脑下棋\n");
			break;
		}
	}
}



char IsWin(char board[ROW][COL], int row, int col)
{
	//玩家赢了返回 *
	// 电脑赢了返回 #
	// 平局返回 q
	// 对局未结束返回 c
	// 行赢
	int i = 0;// 行
	int j = 0;// 列
	char row_first =' ';//行第一个元素
	char col_first =' ';//列第一个元素
	for (i = 0; i < ROW; i++)
	{
		int flag = 1;//flag 为1表示一行全部相等，为0表示一行没有全部相等
		for (j = 0; j < COL; j++)
		{
			row_first = board[i][0];//这一行的第一个元素
			if (board[i][j] != row_first)//拿这一行的所以元素与第一个元素比较，全部相同则赢了
			{
				flag = 0;
				break;//本行没有全部相同，判断下一行
			}	
		}
		if (flag == 1)//如果这一行全部比较完，flag还是1，那么这一行全部相等,赢了
		{
			if (row_first != ' ')//这一行全部相同而且不是' '
			{
				return row_first;
			}
		}
	}
	// 列赢
	int k = 0;// 行
	int h = 0;// 列
	for (h = 0; h < COL; h++)
	{
		//00 10 20 30
		//01 11 21 31
		int flag = 1;//flag 为1表示一列全部相等，为0表示一列没有全部相等
		for (k = 0; k < ROW;k ++)
		{
			char col_frist = board[0][h];//这一列的第一个元素
			if (board[k][h] != col_frist)//拿这一列的所以元素与第一个元素比较，全部相同则赢了
			{
				flag = 0;
				break;//本列没有全部相同，判断下一列
			}
		}
		if (flag == 1)//如果这一列全部比较完，flag还是1，那么这一列全部相等,赢了
		{
			if (col_first != ' ')//这一行全部相同而且不是' '
			{
				return col_first;
			}
		}
	}
		// 对角线赢  第一种情况  
	{
		int m = 0;// 行
		int n = 0;// 列
		int flag = 1;// 1 全部相同   0不完全相同
		char first = board[0][0];
		for (m = 0; m < ROW; m++)
		{
			n = m;
			if (board[m][n] != first)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			if (first != ' ')
			{
				return first;
			}
		}

	}
	//对角线赢  第二种情况
	{
		int x = 0;// 行
		int y = 0;// 列
		int flag = 1;
		char first = board[ROW - 1][0];
		for (x = ROW - 1; x >= 0; x--)
		{
			if (board[x][y] != first)
			{
				flag = 0;
				break;
			}
			if (y < COL)
			{
				y++;
			}
		}
		if (flag == 1)
		{
			if (first != ' ')
			{
				return first;
			}
		}
	}
	//代码走到了这里，说明没有出现赢方
	//那么判断是平局还是对局未结束
	{
		int i = 0;
		int j = 0;
		int flag = 1;//flag为1 表示棋盘里没有' '了，即对局结束了，平局
		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				if (board[i][j] == ' ')
				{
					flag = 0;
				}
			}
		}
		if (flag == 1)
		{
			return 'q';
		}
		if (flag == 0)
		{
			return 'c';
		}
	}
}



void IsWho(int ret)//判断谁赢
{
	switch (ret)
	{
	case '*':
		printf("玩家胜利！\n");
		break;
	case '#':
		printf("电脑胜利！\n");
		break;
	case 'q':
		printf("平局！\n");
		break;
	default:
		break;
	}

}









