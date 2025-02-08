#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdlib.h>

#include "game.h"

void menu()// ��ӡ�˵�
{
	printf("************************\n");
	printf("***1.������    2.�˳�***\n");
	printf("************************\n");
}


void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW, COL);// ��ʼ������,����ÿ�����Ӹ�ֵ
	DispalyBoard(board,ROW,COL);// ��ʾ����ӡ����
	while (1)
	{
		PlayerMove(board, ROW, COL);//�������
		DispalyBoard(board, ROW, COL);//��ӡ����
		char ret=IsWin(board, ROW, COL);//�ж���Ӯ
		IsWho(ret);//�ж�˭Ӯ
		if (ret != 'c')//�����һ��Ӯ�˻���ƽ�֣�������̣�ͬʱ��������ѭ��
		{
			InitBoard(board, ROW, COL);//��ԭ����
			printf("���ֽ���\n��һ�ֿ�ʼ\n");
			DispalyBoard(board, ROW, COL);// ��ʾ����ӡ����
			continue;
		}
		ComputerMove(board,ROW,COL);//��������
		DispalyBoard(board, ROW, COL);//��ӡ����
		ret = IsWin(board, ROW, COL);//�ж���Ӯ
		IsWho(ret);//�ж�˭Ӯ
		if (ret != 'c')//�����һ��Ӯ�˻���ƽ�֣�������̣�ͬʱ��������ѭ��
		{

			InitBoard(board, ROW, COL);//��ԭ����
			printf("���ֽ���\n��һ�ֿ�ʼ\n");
			DispalyBoard(board, ROW, COL);// ��ʾ����ӡ����
			continue;
		}
	}
}




int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {                           //ѭ������ִ��һ�Σ�����ѡ�� do-while ѭ��
		menu();//�˵�
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("����\n");
			break;
		}
	} while (input);
	

	return 0;
}