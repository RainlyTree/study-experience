#pragma once

#define MAX 100

int price[MAX];					//�����Ʒ�۸�
int num[MAX];					//�����Ʒ����
int min_price[MAX][MAX];		//����Żݷ���
int momey[MAX][MAX];			//������Ž�
int min_number;					//�Żݷ�������

void get_mesage();					//��ȡ��Ʒ��Ϣ

void min_momey();				//�ö�̬�滮��ȡ���ٵ�Ǯ�ķ���

void show();					//��ȡ��Ķ���������۸�