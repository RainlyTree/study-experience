//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int binary_search(int a[], int number, int length);
//	int num = 0;
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int length = sizeof(a) / sizeof(a[0]);
//	printf("输入需要查找的数:\n");
//	scanf("%d", &num);
//	if (binary_search(a, num, length) != -1)
//		printf("find it :%d \n", binary_search(a, num, length));
//	else
//	{
//		printf(" not find \n");
//	}
//	system("pause");
//	return 0;
//}
//
//
//int binary_search(int a[], int number, int length)
//{
//	int left = 0;
//	int right = length - 1;
//	int mid = (left-right)/2 + right;
//	while (left <= right)
//	{
//		if (a[mid] > number)
//		{
//			right = mid - 1;
//			mid = (left - right) / 2 + right;
//		}
//		else if (a[mid] < number)
//		{
//			left = mid + 1;
//			mid = (left - right) / 2 + right;
//		}
//		else
//			break;
//	}
//	if (left <= right)
//		return mid;
//	else
//	{
//		return -1;
//	}
//	return 0;
//}