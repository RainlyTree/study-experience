#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	//   法1
	//int water = 20;
	//int count = 0;
	//int null_water = 0;		//一次喝完漏掉的空瓶子
	////count = water;
	//while (water != 0)
	//{
	//	count += water;
	//	if (water % 2 == 1)
	//	{
	//		null_water++;
	//	}
	//	if (null_water == 2)
	//	{
	//		count++;
	//		null_water = 1;
	//	}
	//	water = water >> 1;
	//	printf("%d", count);
	//}

	//    法二
	int momey = 20;
	int empty = 0;
	int total = 0;
	total = momey;
	empty = momey;
	while (empty >= 2)
	{
		total = total + empty/2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d", total);
	system("pause");
	return 0;
}