#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"min_price.h"

void get_mesage()
{
	int i = 0, j = 0;
	int n = 0;					//获取方案中商品种类
	int shop_number = 0;		//商品个数
	printf("请输入第一个商品的单价:");
	scanf("%d", &price[0]);
	printf("请输入第二个商品的单价:");
	scanf("%d", &price[1]);
	printf("优惠方案的个数:");
	scanf("%d", &min_number);
	for (i = 1; i <= min_number; i++)
	{
		printf("第%d种优惠方案中的商品种类:", i);
		scanf("%d", &n);
		for (j = 1; j <= n; j++)
		{
			printf("第%d个商品个数:", j);
			scanf("%d", &shop_number);
			min_price[i][j] = shop_number;
		}
		printf("优惠后的价格:");
		scanf("%d", &min_price[i][0]);
	}
}

void min_momey()
{
	int i = 0;				//表的每一行
	int j = 0;				//表的每一列
	int k = 0;				//优惠方案的个数
	{
		int i = 0;
		int j = 0;
		int k = 0;
		int min = 0;				//中间量 将目前的优惠方案价钱放入
		for (i = 0; i <= num[0]; i++)
		{
			for (j = 0; j <= num[1]; j++)
			{
				momey[i][j] = i * price[0] + j * price[1];		//按照每一种货物的单价计算
				for (k = 1; k <= min_number; k++)	//使用每一种优惠方案 找出最优方案的价钱
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
	printf("购买第一种和第二种商品的数量：");
	scanf("%d %d", &num[0], &num[1]);
	if (num[0] > MAX || num[1] > MAX)
	{
		printf("内存不够！\n");
		return;
	}
	min_momey();
	printf("最终价格为：%d\n", momey[num[0]][num[1]]);
}