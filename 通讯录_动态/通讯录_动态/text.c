#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"contact.h"

void menu()
{
	printf("********1. ADD*******2.search*******\n");
	printf("********3. del*******4.show  *******\n");
	printf("********5. clear*****6.sort  *******\n");
	printf("********7.Destroy****8.change*******\n");
	printf("***************0. exit**************\n");
}

void start()
{
	int input = 0;
	//��ʼ��ͨѶ¼ ���� usedSize
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("input you operation:");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			AddContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case show:
			ShowContact(&con);
			break;
		case clear:
			ClearContact(&con);
			break;
		case sort:
			SortContact(&con);
			break;
		case Destory:
			DestroyContact(&con);
			break;
		case change:
			ChangeContact(&con);
		case EXIT:
			break;
		default:
			printf("��������");
			break;
		}
	} while (input);
}


int main()
{
	start();
	system("pause");
	return 0;
}