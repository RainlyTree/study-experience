#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int init(int arr[], int size)  //初始化数组
{
	int i = 0;
	for (i = 0; i < size; i++)
		arr[i] = i;
	return 0;
}

int empty(int arr[], int size)
{
	memset(arr, 0, sizeof(arr[0]) * size);
	return 0;
}

int reverse(int arr[], int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int main()
{
	int arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);
	init(arr, size);
	empty(arr, size);
	reverse(arr, size);
	system("pause");
	return 0;
}