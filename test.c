#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdlib.h>

#include "game.h"

void menu()// 打印菜单
{
	printf("************************\n");
	printf("***1.三子棋    2.退出***\n");
	printf("************************\n");
}


void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW, COL);// 初始化棋盘,即给每个格子赋值
	DispalyBoard(board,ROW,COL);// 显示、打印棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		DispalyBoard(board, ROW, COL);//打印棋盘
		char ret=IsWin(board, ROW, COL);//判断输赢
		IsWho(ret);//判断谁赢
		if (ret != 'c')//如果有一方赢了或者平局，清空棋盘，同时跳出本次循环
		{
			InitBoard(board, ROW, COL);//复原棋盘
			printf("本局结束\n下一局开始\n");
			DispalyBoard(board, ROW, COL);// 显示、打印棋盘
			continue;
		}
		ComputerMove(board,ROW,COL);//电脑下棋
		DispalyBoard(board, ROW, COL);//打印棋盘
		ret = IsWin(board, ROW, COL);//判断输赢
		IsWho(ret);//判断谁赢
		if (ret != 'c')//如果有一方赢了或者平局，清空棋盘，同时跳出本次循环
		{

			InitBoard(board, ROW, COL);//复原棋盘
			printf("本局结束\n下一局开始\n");
			DispalyBoard(board, ROW, COL);// 显示、打印棋盘
			continue;
		}
	}
}




int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {                           //循环至少执行一次，所以选择 do-while 循环
		menu();//菜单
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("错误\n");
			break;
		}
	} while (input);
	

	return 0;
}