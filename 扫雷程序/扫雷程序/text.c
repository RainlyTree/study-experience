#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"mine_clearance…®¿◊.h"

void menu()
{
	{
		printf("**********************\n");
		printf("*****  1. play   *****\n");
		printf("*****  0. exit   *****\n");
		printf("**********************\n");
	}
}

void mine_clear()
{
	char Mine[ROWS][COLS];
	char Show[ROWS][COLS];
	In_mine(Mine, ROWS, COLS);
	Out_mine(Show, ROWS, COLS);
	Set_Mine(Mine, ROW, COL, Mine_number);
	Print(Show, ROW, COL);
	Find_mine(Mine, Show, ROW, COL);
}

int main()
{
	int number = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		scanf("%d", &number);
		switch(number)
		{
		case 1:
			mine_clear();
			break;
		case 0:
			break;
		default:
			printf(" ‰»Î¥ÌŒÛ");
			break;
		}
	} while (number);
	system("pause");
	return 0;
}