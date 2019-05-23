#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"tic-tac-toe.h"

void Init_board(char arr[ROWS][COLS], int ROW, int COL)        //��ʼ������
{
	memset(arr, ' ', ROWS*COLS * sizeof(arr[0][0]));           //����Ԫ�ر�Ϊ��
}

void Display_board(char arr[ROWS][COLS], int ROW, int COL)     //��ӡ����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)								//����
	{
		for (j = 0; j < COL; j++)							//��ӡ�еĵ�һ����
		{
			printf(" %c ", arr[i][j]);
			if (j < ROW - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < ROW - 1)									//��ӡ�еĵڶ�����
		{
			for (j = 0; j < COL; j++)
			{
				printf("---");
				if (j < COL - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void Player_move(char arr[ROWS][COLS], int ROW, int COL)		//�����
{
	int a = 0;
	int b = 0;
	while (1)
	{
		printf("�������� :");
		scanf("%d %d", &a, &b);
		if (a < 1 || a >ROW || b < 1 || b > COL)
		{
			printf("�Ƿ�����");
		}
		if (arr[a - 1][b - 1] != ' ')                          //���յ������ʵ�������±��һ
		{
			printf("�Ѿ��������ˣ�");
		}
		if (arr[a - 1][b - 1] == ' ')
		{
			arr[a - 1][b - 1] = '*';
			break;
		}
	}
}

char full_borad(char arr[ROWS][COLS], int ROW, int COL) //�ж��Ƿ�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (arr[i][j] == ' ')						//�пղ�Ϊ��
				return ' ';
		}
	}
	return 'q';
}

char CheckWin(char arr[ROWS][COLS], int ROW, int COL)			//�ж���Ӯ  '*'��һ�ʤ 'q'ƽ�� '#'���Ի�ʤ
{
	int people = 0;
	int computer = 0;
	char full;
	people = ROW_win(arr, ROW, COL, '*');//�ж��л�ʤ
	computer = ROW_win(arr, ROW, COL, '#');
	if (people == ROW)
	{
		return '*';
	}

	if (computer == ROW)
	{
		return '#';
	}

	people = COL_win(arr, ROW, COL, '*'); //�ж��л�ʤ
	computer = COL_win(arr, ROW, COL, '#');
	if (people == COL)
		return '*';
	if (computer == COL)
		return '#';

	people = Sideways(arr, ROW, COL, '*'); //�ж�б�һ�ʤ
	computer = Sideways(arr, ROW, COL, '#');
	if (people == COL)
		return '*';
	if (computer == COL)
		return '#';

	people = Sideways2(arr, ROWS, COLS, '*'); //�ж�б���ʤ
	computer = Sideways2(arr, ROWS, COLS, '#');
	if (people == COLS)
		return '*';
	if (computer == COLS)
		return '#';

	full = full_borad(arr, ROWS, COLS);      //�ж��Ƿ�ƽ��
	if (full == 'q')
		return ' ';

	return 'q';
}

int ROW_win(char arr[ROWS][COLS], int ROW, int COL, char c) //���Ż�ʤ���س��ȣ���Ȼ����0
{
	int count = 0;
	int j = 0;
	int i = 0;
	for (j = 0; j < COLS; j++)
	{
		for (i = 0; i < ROWS; i++)
		{
			if (arr[j][i] == c)
				count++;
		}
		if (count == ROWS)                //�ж�ÿһ��
			break;
		else
			count = 0;
	}
	return count;
}
int COL_win(char arr[ROWS][COLS], int ROW, int COL, char c) //���Ż�ʤ���س��ȣ���Ȼ����0
{
	int count = 0;
	int j = 0;
	int i = 0;
	for (j = 0; j < COLS; j++)
	{
		for (i = 0; i < ROWS; i++)
		{
			if (arr[i][j] == c)
				count++;
		}
		if (count == COLS)                  //�ж�ÿһ��
			break;
		else
			count = 0;
	}
	return count;
}
int Sideways(char arr[ROWS][COLS], int ROW, int COL, char c)//б��������
{
	int count = 0;
	int j = 0;
	int i = 0;
	for (i = 0; i < ROWS; i++)
	{
		if (arr[i][j] == c)
			count++;
		j++;
	}
	if (count != ROWS)
		count = 0;
	return count;
}
int Sideways2(char arr[ROWS][COLS], int ROW, int COL, char c)//б��������
{
	int count = 0;
	int i = ROWS - 1;
	int j = COLS - 1;
	for (i = 0; i > ROWS; i++)
	{
		if (arr[i][j] == c)
			count++;
		j--;
	}
	if (count != ROWS)
		count = 0;
return count;
}

void Computer_move(char arr[ROWS][COLS], int ROW, int COL)		//������
{
	int a = 0;
	int b = 0;
	while (1)
	{
		a = rand() % ROWS;
		b = rand() % COLS;
		if (arr[a][b] == ' ')
		{
			arr[a][b] = '#';
			break;
		}
	}
}