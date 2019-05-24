#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"mine_clearance扫雷.h"

void In_mine(char Mine[ROWS][COLS], int row, int col)			//内置扫雷盘重置
{
	memset(Mine, '0', row*col * sizeof(Mine[0][0]));
}

void Out_mine(char Show[ROWS][COLS], int row, int col)			//玩家扫雷盘重置
{
	memset(Show, '*', row*col * sizeof(Show[0][0]));
}

void Print(char Mine[ROWS][COLS], int row, int col)				//显示扫雷盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)			//打印行标
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)			
	{
		for (j = 1; j <= col; j++)
		{
			if (j == 1)					//顺便打印列标
				printf("%d %c", i, Mine[i][j]);
			else
				printf(" %c", Mine[i][j]);
		}
		printf("\n");
	}
}

void Set_Mine(char Mine[ROWS][COLS], int row, int col, int n)			//放雷
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

static void Move_Mine(char Mine[ROWS][COLS], int x, int y)			//当第一次猜到了 将雷移开
{
	Mine[x][y] = '0';				//将雷清掉
	int a = 0;
	int b = 0;
	while (1)
	{
		a = rand() % ROW + 1;
		b = rand() % COL + 1;
		if (Mine[a][b] != '1')			//防止随机到的雷放到原本有雷的区域
		{
			Mine[a][b] = '1';
			break;
		}
	}
}

static int Mine_Count(char Mine[ROWS][COLS], int x, int y)			//统计一圈雷的个数
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

static int Win(char Show[ROWS][COLS], int row, int col)			//获胜条件
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

int Find_mine(char Mine[ROWS][COLS],char Show[ROWS][COLS], int row, int col)			//找雷
{
	int x = 0;
	int y = 0;
	int flag = 1;		//判断是否为第一步
	while (Win(Show,row, col) != Mine_number)
	{
		//Print(Mine, ROW, COL);
		printf("请输入坐标:");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > row || y < 1 || y > col)
		{
			printf("输入坐标有误\n");
		}
		if (Show[x][y] != '*')
		{
			printf("该坐标已经显示\n");
		}
		if (Mine[x][y] == '1' && flag == 1)		//第一次触雷
		{
			Move_Mine(Mine, x, y);				//移动雷
			Open_Mine(Mine, Show, x, y);		//将附近没有雷的地方开了
			Print(Show, ROW, COL);				//显示棋盘
			flag = 0;
		}
		if (Mine[x][y] == '1')					//待测试
		{
			printf("你被炸死了\n");
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
	printf("成功扫雷\n");
	return 0;
}