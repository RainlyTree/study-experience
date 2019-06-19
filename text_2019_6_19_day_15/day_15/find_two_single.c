//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//int main()
//{
//	int arr[10] = { 1,3,2,5,5,3,2,7,1,9 };
//	int x = 0;
//	int y = 0;
//	int mem = arr[0];
//	int mark = 1;
//	int i = 0;
//	for (i = 1; i < 10; i++)
//	{
//		mem = mem ^ arr[i];
//	}
//	while (((mem >> 1) & 1) != 1)
//	{
//		mem = mem / 2;
//		mark++;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (((arr[i] >> mark) & 1) == 0)
//		{
//			x = x ^ arr[i];
//		}
//		else
//		{
//			y = y ^ arr[i];
//		}
//	}
//	printf("%d %d", x, y);
//	system("pause");
//	return 0;
//}