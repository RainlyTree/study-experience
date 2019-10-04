#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//int find_number(int arr[][3],int row,int col, int number)
//{
//	int i = 0;
//	int j = col - 1;
//	while (j >= 0 && i <= 2)
//	{
//		if (arr[i][j] == number)
//			return 1;
//		else if (arr[i][j] < number)
//			i++;
//		else
//			j++;
//	}
//	return 0;
//}

int find_number(int arr[][3], int *row, int *col, int number)
{
	int i = 0;
	int j = *col - 1;
	while (j >= 0 && i <= 2)
	{
		if (arr[i][j] == number)
		{
			*row = i;
			*col = j;
			return 1;
		}
		if (arr[i][j] < number)
			i++;
		else
			j--;
	}
	return 0;
}

int main()
{
	int number = 0;
	int arr[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int row = 3;
	int col = 3;
	scanf("%d", &number);
	int ret = find_number(arr, &row, &col, number);
	if (ret == 1)
		printf("find it\n");
	else
		printf("not find\n");
	printf("%d ,%d", row, col);
	//system("pause");
	return 0;
}