#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"min_price.h"

void get_mesage()
{
	int i = 0, j = 0;
	int n = 0;					//��ȡ��������Ʒ����
	int shop_number = 0;		//��Ʒ����
	printf("�������һ����Ʒ�ĵ���:");
	scanf("%d", &price[0]);
	printf("������ڶ�����Ʒ�ĵ���:");
	scanf("%d", &price[1]);
	printf("�Żݷ����ĸ���:");
	scanf("%d", &min_number);
	for (i = 1; i <= min_number; i++)
	{
		printf("��%d���Żݷ����е���Ʒ����:", i);
		scanf("%d", &n);
		for (j = 1; j <= n; j++)
		{
			printf("��%d����Ʒ����:", j);
			scanf("%d", &shop_number);
			min_price[i][j] = shop_number;
		}
		printf("�Żݺ�ļ۸�:");
		scanf("%d", &min_price[i][0]);
	}
}

void min_momey()
{
	int i = 0;				//���ÿһ��
	int j = 0;				//���ÿһ��
	int k = 0;				//�Żݷ����ĸ���
	{
		int i = 0;
		int j = 0;
		int k = 0;
		int min = 0;				//�м��� ��Ŀǰ���Żݷ�����Ǯ����
		for (i = 0; i <= num[0]; i++)
		{
			for (j = 0; j <= num[1]; j++)
			{
				momey[i][j] = i * price[0] + j * price[1];		//����ÿһ�ֻ���ĵ��ۼ���
				for (k = 1; k <= min_number; k++)	//ʹ��ÿһ���Żݷ��� �ҳ����ŷ����ļ�Ǯ
				{
					int fir = i - min_price[k][1];
					int sec = j - min_price[k][2];
					if (fir >= 0 && sec >= 0)
					{
						min = momey[fir][sec] + min_price[k][0];
						if (min < momey[i][j])
							momey[i][j] = min;
					}
				}
			}
		}
	}
}

void show()
{
	printf("�����һ�ֺ͵ڶ�����Ʒ��������");
	scanf("%d %d", &num[0], &num[1]);
	if (num[0] > MAX || num[1] > MAX)
	{
		printf("�ڴ治����\n");
		return;
	}
	min_momey();
	printf("���ռ۸�Ϊ��%d\n", momey[num[0]][num[1]]);
}