#pragma once
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<Windows.h>

#define ROWS 3			 //�����еĴ�С
#define COLS 3           //�����еĴ�С

void Init_board(char arr[ROWS][COLS], int ROW , int COL);        //��ʼ������
void Display_board(char arr[ROWS][COLS], int ROW , int COL);     //��ӡ����
void Player_move(char arr[ROWS][COLS], int ROW, int COL);		//�����
char CheckWin(char arr[ROWS][COLS], int ROW, int COL);			//�ж���Ӯ
void Computer_move(char arr[ROWS][COLS],int ROW, int COL);		//������