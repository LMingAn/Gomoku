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

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家下棋：\n");
	while (1)
	{
		printf("请输入坐标下棋：\n");
		scanf_s("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//下棋
			//检查坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标占用，请重试\n");
			}
		}
		else
		{
			printf("坐标非法，请重试\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	
	printf("电脑下棋：\n");
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
	//行判断
	for (x = 0; x < row; x++)
	{
		//当一行上的三个棋子相同且都不为空格时，游戏结束
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2] && board[x][1] != ' ')
			return board[x][1];//返回棋子，则棋子对应方获胜
	}
	//列判断
	for (y = 0; y < col; y++)
	{
		//当一列上的三个棋子相同且都不为空格时，游戏结束
		if (board[0][y] == board[1][y] && board[1][y] == board[2][y] && board[1][y] != ' ')
			return board[1][y];
	}
	//主对角线判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	//副对角线判断
	int full = Full(board, row, col);
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	else if (full == 1)//Full函数用于判断棋盘是否已满
		return 'C';
	else
		return 'N';
}