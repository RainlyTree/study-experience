#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"tic-tac-toe.h"

void menu()
{
	printf("*********************************\n");
	printf("*********1   ������Ϸ    ********\n");
	printf("*********0   �˳���Ϸ    ********\n");
	printf("*********************************\n");
}

void tic_tac()
{
	char ret = 0;
	char arr[ROWS][COLS];
	Init_board(arr, ROWS, COLS);          //��ʼ������
	Display_board(arr, ROWS, COLS);       //��ӡ����
	while (1)
	{
		Player_move(arr, ROWS, COLS);		//�����
		Display_board(arr, ROWS, COLS);		//��ʾ����
		ret = CheckWin(arr, ROWS, COLS);	//�ж���Ӯ
		if (ret != 'q')
		{
			break;
		}
		Computer_move(arr, ROWS, COLS);		//������
		Display_board(arr, ROWS, COLS);		//��ʾ����
		ret = CheckWin(arr, ROWS, COLS);	//�ж���Ӯ
		if (ret != 'q')
		{
			break;
		}
	}
	if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	if (ret == ' ')
	{
		printf("ƽ��");
	}

}

void test()
{
	int number = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &number);
		switch (number)
		{
		case 1:
			tic_tac();
			break;
		case 2:
			break;
		default:
			printf("�����������ѡ��\n");
			break;
		}
	} while (number);
}

int main()
{
	test();
	return 0;
}