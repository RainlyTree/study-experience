#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROW 9     //��ʾ��ɨ����
#define COL 9

#define ROWS 11	  //���õ�ɨ����
#define COLS 11

#define Mine_number 10	//�׵ĸ���

void Set_Mine(char Mine[ROWS][COLS], int row, int col, int n);			//����
//nΪ���׸���

void Print(char Mine[ROWS][COLS], int row, int col);			//��ʾɨ����

void In_mine(char Mine[ROWS][COLS], int row, int col);			//����ɨ��������
//��Ҫ��������������ʾ ����Ϊ��������

void Out_mine(char Show[ROWS][COLS], int row, int col);			//���ɨ��������
// ��'*'�ڸ��·�������ɨ����

int Find_mine(char Mine[ROWS][COLS],char Show[ROWS][COLS], int row, int col);			//����