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
	//打印棋盘
	for (i = 0; i < row; i++)
	{
		//打印键盘的输入行
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印键盘的分割行
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