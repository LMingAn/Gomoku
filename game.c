#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	//��ӡ����
	for (i = 0; i < row; i++)
	{
		//��ӡ���̵�������
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ���̵ķָ���
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("������壺\n");
	while (1)
	{
		printf("�������������壺\n");
		scanf_s("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����
			//��������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("����ռ�ã�������\n");
			}
		}
		else
		{
			printf("����Ƿ���������\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	
	printf("�������壺\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int Full(char board[ROW][COL], int row, int col)
{
	int x, y;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (board[x][y] != ' ')
				return 1;
		}
	}
	return 0;
}

char Win(char board[ROW][COL], int row, int col)
{
	int x, y;
	//���ж�
	for (x = 0; x < row; x++)
	{
		//��һ���ϵ�����������ͬ�Ҷ���Ϊ�ո�ʱ����Ϸ����
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2] && board[x][1] != ' ')
			return board[x][1];//�������ӣ������Ӷ�Ӧ����ʤ
	}
	//���ж�
	for (y = 0; y < col; y++)
	{
		//��һ���ϵ�����������ͬ�Ҷ���Ϊ�ո�ʱ����Ϸ����
		if (board[0][y] == board[1][y] && board[1][y] == board[2][y] && board[1][y] != ' ')
			return board[1][y];
	}
	//���Խ����ж�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	//���Խ����ж�
	int full = Full(board, row, col);
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	else if (full == 1)//Full���������ж������Ƿ�����
		return 'C';
	else
		return 'N';
}