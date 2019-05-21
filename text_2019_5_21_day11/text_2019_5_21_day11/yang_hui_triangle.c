#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 10

//void print_yang(int line)
//{
//	int i = 0;
//	int j = 0;
//	int arr[N][N] = { 0 };
//	for (i = 0; i < N; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//	}
//	for (i = 0; i < N; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < N-i-1; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf(" %d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//
//int main()
//{
//	print_yang(N);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	int tge[N][N];
//	//先打印每一行的第一个和最后一个；
//	for (i = 0; i < N; i++)
//	{
//		tge[i][0] = 1;
//		tge[i][i] = 1;
//	}
//	//打印中间部分
//	for (i = 2; i < N; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			tge[i][j] = tge[i - 1][j - 1] + tge[i - 1][j];
//		}
//	}
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < 2 * (N - i); j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%4d", tge[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//}