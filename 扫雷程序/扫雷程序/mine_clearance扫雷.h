#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROW 9     //显示的扫雷盘
#define COL 9

#define ROWS 11	  //内置的扫雷盘
#define COLS 11

#define Mine_number 10	//雷的个数

void Set_Mine(char Mine[ROWS][COLS], int row, int col, int n);			//放雷
//n为放雷个数

void Print(char Mine[ROWS][COLS], int row, int col);			//显示扫雷盘

void In_mine(char Mine[ROWS][COLS], int row, int col);			//内置扫雷盘重置
//需要将附近的雷数显示 内置为符号数字

void Out_mine(char Show[ROWS][COLS], int row, int col);			//玩家扫雷盘重置
// 用'*'遮盖下方的内置扫雷盘

int Find_mine(char Mine[ROWS][COLS],char Show[ROWS][COLS], int row, int col);			//找雷