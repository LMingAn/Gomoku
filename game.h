#pragma once

//ͷ�ļ��İ���
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//���ŵĶ���
#define ROW 3
#define COL 3


//����������

//��ʼ�����̵ĺ���
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ���̵ĺ���
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������ĺ���
void PlayerMove(char board[ROW][COL], int row, int col);

//��������ĺ���
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ϸ״���ĺ���
char Win(char board[ROW][COL], int row, int col);