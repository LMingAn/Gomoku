//前言：
//三子棋共包含三部分：
//test.c -- 测试游戏的逻辑
//game.h -- 关于游戏相关的函数声明，符号声明头文件的包含
//game.c -- 游戏相关函数的实现



#include"game.h"//自己定义的头文件需要用双引号引用
void menu()
{
	printf("***********************************\n");
	printf("*****         1. play         *****\n");
	printf("*****         0. exit         *****\n");
	printf("***********************************\n");
}
void game()
{
	//存储数据 - 二维数组
	//此处如果指定了⌈棋盘⌋的大小，即board[3][3]，那么以后想更改棋盘大小就需要改此处以及一系列的代码数据，非常麻烦，所以在此处需要新建一个头文件
	char board[ROW][COL];

	//初始化棋盘 - 初始化空格
	InitBoard(board, ROW, COL);

	//打印棋盘 - 本质是打印数组的内容
	DisplayBoard(board, ROW, COL);

	char check;//避免在while循环中重复定义
	//check共有四种情况用于判断游戏状况
	//check = * -- 玩家获胜
	//check = # -- 电脑获胜
	//以上两种为了避免在Win函数中多定义一个变量用于返回游戏状况，直接返回棋子本身
	//check = N -- 平局
	//check = C -- 游戏继续

	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否获胜
		check = Win(board, ROW, COL);//进行游戏状况判断
		if (check != 'C')//当棋盘上有特殊情况不能继续游戏时，跳出循环（游戏）开始进行结果判断
			break;
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		check = Win(board, ROW, COL);//判断游戏状况
		if (check != 'C')//同上
			break;
	}
	//开始进行游戏结果判断
	if (check == '*')
		printf("玩家获胜\n");
	else if (check == '#')
		printf("电脑获胜\n");
	else if (check == 'N')
		printf("平局\n");
	else
		printf("无子可放，平局\n");
}
int main()
{
	int input = 0;
	//srand只需要定义一次
	//srand需要引用stdlib头文件
	//time需要引用time头文件
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}