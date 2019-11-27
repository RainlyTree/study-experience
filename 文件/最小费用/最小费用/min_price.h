#pragma once

#define MAX 100

int price[MAX];					//存放商品价格
int num[MAX];					//存放商品数量
int min_price[MAX][MAX];		//存放优惠方案
int momey[MAX][MAX];			//存放最优解
int min_number;					//优惠方案个数

void get_mesage();					//获取产品信息

void min_momey();				//用动态规划获取最少的钱的方案

void show();					//获取买的东西，输出价格