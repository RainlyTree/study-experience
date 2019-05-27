#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"mine_clearanceɨ��.h"

void In_mine(char Mine[ROWS][COLS], int row, int col)			//����ɨ��������
{
	memset(Mine, '0', row*col * sizeof(Mine[0][0]));
}

void Out_mine(char Show[ROWS][COLS], int row, int col)			//���ɨ��������
{
	memset(Show, '*', row*col * sizeof(Show[0][0]));
}

void Print(char Mine[ROWS][COLS], int row, int col)				//��ʾɨ����
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)			//��ӡ�б�
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)			
	{
		for (j = 1; j <= col; j++)
		{
			if (j == 1)					//˳���ӡ�б�
				printf("%d %c", i, Mine[i][j]);
			else
				printf(" %c", Mine[i][j]);
		}
		printf("\n");
	}
}

void Set_Mine(char Mine[ROWS][COLS], int row, int col, int n)			//����
{
	int x = 0;
	int y = 0;
	while (n)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (Mine[x][y] == '0')
		{
			Mine[x][y] = '1';
			n--;
		}
	}
}

static void Move_Mine(char Mine[ROWS][COLS], int x, int y)			//����һ�βµ��� �����ƿ�
{
	Mine[x][y] = '0';				//�������
	int a = 0;
	int b = 0;
	while (1)
	{
		a = rand() % ROW + 1;
		b = rand() % COL + 1;
		if (Mine[a][b] != '1')			//��ֹ��������׷ŵ�ԭ�����׵�����
		{
			Mine[a][b] = '1';
			break;
		}
	}
}

static int Mine_Count(char Mine[ROWS][COLS], int x, int y)			//ͳ��һȦ�׵ĸ���
{
	int number = 0;
	number = Mine[x - 1][y] 
		   + Mine[x - 1][y + 1] 
		   + Mine[x][y + 1]
		   + Mine[x + 1][y + 1] 
		   + Mine[x + 1][y] 
		   + Mine[x + 1][y - 1]
		   + Mine[x][y - 1] 
		   + Mine[x - 1][y - 1]
		   - 8 * '0';
	return number;
}

static int Open_Mine(char Mine[ROWS][COLS],char Show[ROWS][COLS], int x, int y)
{
	if (Mine_Count(Mine, x, y) == 0)
	{
		Show[x][y] = '0';
		if ((x - 1) >= 1 && (x - 1) <= ROW && (y - 1) >= 1 && (y - 1) <= COL && Show[x - 1][y - 1] == '*')
			Open_Mine(Mine, Show, x - 1, y - 1);
		if ((x) >= 1 && (x) <= ROW && (y - 1) >= 1 && (y - 1) <= COL && Show[x][y - 1] == '*')
			Open_Mine(Mine, Show, x, y - 1);
		if ((x + 1) >= 1 && (x + 1) <= ROW && (y - 1) >= 1 && (y - 1) <= COL && Show[x + 1][y - 1] == '*')
			Open_Mine(Mine, Show, x + 1, y - 1);
		if ((x + 1) >= 1 && (x + 1) <= ROW && (y) >= 1 && (y) <= COL && Show[x + 1][y] == '*')
			Open_Mine(Mine, Show, x + 1, y);
		if ((x + 1) >= 1 && (x + 1) <= ROW && (y + 1) >= 1 && (y + 1) <= COL && Show[x + 1][y + 1] == '*')
			Open_Mine(Mine, Show, x + 1, y + 1);
		if ((x) >= 1 && (x) <= ROW && (y - 1) >= 1 && (y - 1) <= COL && Show[x][y - 1] == '*')
			Open_Mine(Mine, Show, x, y - 1);
		if ((x - 1) >= 1 && (x - 1) <= ROW && (y + 1) >= 1 && (y + 1) <= COL && Show[x - 1][y + 1] == '*')
			Open_Mine(Mine, Show, x - 1, y + 1);
		if ((x - 1) >= 1 && (x - 1) <= ROW && (y) >= 1 && (y) <= COL && Show[x - 1][y] == '*')
			Open_Mine(Mine, Show, x - 1, y);
	}
	else
	{
		Show[x][y] = Mine_Count(Mine, x, y) + '0';
	}
	return 0;
}

static int Win(char Show[ROWS][COLS], int row, int col)			//��ʤ����
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (Show[i][j] == '*')
				count++;
		}
	}
	return count;
}

int Find_mine(char Mine[ROWS][COLS],char Show[ROWS][COLS], int row, int col)			//����
{
	int x = 0;
	int y = 0;
	int flag = 1;		//�ж��Ƿ�Ϊ��һ��
	while (Win(Show,row, col) != Mine_number)
	{
		//Print(Mine, ROW, COL);
		printf("����������:");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > row || y < 1 || y > col)
		{
			printf("������������\n");
		}
		if (Show[x][y] != '*')
		{
			printf("�������Ѿ���ʾ\n");
		}
		if (Mine[x][y] == '1' && flag == 1)		//��һ�δ���
		{
			Move_Mine(Mine, x, y);				//�ƶ���
			Open_Mine(Mine, Show, x, y);		//������û���׵ĵط�����
			Print(Show, ROW, COL);				//��ʾ����
			flag = 0;
		}
		if (Mine[x][y] == '1')					//������
		{
			printf("�㱻ը����\n");
			Print(Mine, ROW, COL);
			return 0;
		}
		if (Mine[x][y] == '0')
		{
			Open_Mine(Mine, Show, x, y);
			Print(Show, ROW, COL);
			flag = 0;
		}
	}
	printf("�ɹ�ɨ��\n");
	return 0;
}