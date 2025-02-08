#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <string.h>

void InitBoard(char board[ROW][COL], int row, int col)//��ʼ������,����ÿ�����Ӹ�ֵ
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

void DispalyBoard(char board[ROW][COL], int row, int col)//��ӡ����
{
	int i = 0;
	int j = 0;
	int k = 0;
	//��ӡ3x3 ������
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

	//��ӡROW * COL ������
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



void PlayerMove(char board[ROW][COL], int row, int col)//�������
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("�������\n");
		printf("����������: >");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)//�ж�����������Ƿ������̷�Χ��
		{
			if (board[x - 1][y - 1] == ' ')//�ж��������������Ƿ��Ѿ���������
			{
				board[x - 1][y - 1] = '*';//���������*��ʾ
				break;
			}
			else
			{
				printf("��������������,���������룡\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}



void ComputerMove(char board[ROW][COL], int row, int col)//��������   �����������
{
	
	while (1)
	{
		int x = rand() % ROW;//rand()��������������ķ�Χ��0~65535��ģ��ROW��ֵ��0~ROW-1
		int y = rand() % COL;//rand()����ʹ��ǰ��Ҫ��ʹ��srand()��������������
		//��ʱ x��y�ķ�Χ�������̷�Χ��
		if (board[x][y] == ' ')//�ж���������Ƿ�������
		{
			board[x][y] = '#';
			printf("��������\n");
			break;
		}
	}
}



char IsWin(char board[ROW][COL], int row, int col)
{
	//���Ӯ�˷��� *
	// ����Ӯ�˷��� #
	// ƽ�ַ��� q
	// �Ծ�δ�������� c
	// ��Ӯ
	int i = 0;// ��
	int j = 0;// ��
	char row_first =' ';//�е�һ��Ԫ��
	char col_first =' ';//�е�һ��Ԫ��
	for (i = 0; i < ROW; i++)
	{
		int flag = 1;//flag Ϊ1��ʾһ��ȫ����ȣ�Ϊ0��ʾһ��û��ȫ�����
		for (j = 0; j < COL; j++)
		{
			row_first = board[i][0];//��һ�еĵ�һ��Ԫ��
			if (board[i][j] != row_first)//����һ�е�����Ԫ�����һ��Ԫ�رȽϣ�ȫ����ͬ��Ӯ��
			{
				flag = 0;
				break;//����û��ȫ����ͬ���ж���һ��
			}	
		}
		if (flag == 1)//�����һ��ȫ���Ƚ��꣬flag����1����ô��һ��ȫ�����,Ӯ��
		{
			if (row_first != ' ')//��һ��ȫ����ͬ���Ҳ���' '
			{
				return row_first;
			}
		}
	}
	// ��Ӯ
	int k = 0;// ��
	int h = 0;// ��
	for (h = 0; h < COL; h++)
	{
		//00 10 20 30
		//01 11 21 31
		int flag = 1;//flag Ϊ1��ʾһ��ȫ����ȣ�Ϊ0��ʾһ��û��ȫ�����
		for (k = 0; k < ROW;k ++)
		{
			char col_frist = board[0][h];//��һ�еĵ�һ��Ԫ��
			if (board[k][h] != col_frist)//����һ�е�����Ԫ�����һ��Ԫ�رȽϣ�ȫ����ͬ��Ӯ��
			{
				flag = 0;
				break;//����û��ȫ����ͬ���ж���һ��
			}
		}
		if (flag == 1)//�����һ��ȫ���Ƚ��꣬flag����1����ô��һ��ȫ�����,Ӯ��
		{
			if (col_first != ' ')//��һ��ȫ����ͬ���Ҳ���' '
			{
				return col_first;
			}
		}
	}
		// �Խ���Ӯ  ��һ�����  
	{
		int m = 0;// ��
		int n = 0;// ��
		int flag = 1;// 1 ȫ����ͬ   0����ȫ��ͬ
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
	//�Խ���Ӯ  �ڶ������
	{
		int x = 0;// ��
		int y = 0;// ��
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
	//�����ߵ������˵��û�г���Ӯ��
	//��ô�ж���ƽ�ֻ��ǶԾ�δ����
	{
		int i = 0;
		int j = 0;
		int flag = 1;//flagΪ1 ��ʾ������û��' '�ˣ����Ծֽ����ˣ�ƽ��
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



void IsWho(int ret)//�ж�˭Ӯ
{
	switch (ret)
	{
	case '*':
		printf("���ʤ����\n");
		break;
	case '#':
		printf("����ʤ����\n");
		break;
	case 'q':
		printf("ƽ�֣�\n");
		break;
	default:
		break;
	}

}









