//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<windows.h>
//
//////����һ���������飬ʵ��һ�������� 
//////�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//////����ż��λ������ĺ�벿�֡�
//
//void swap(int* fir, int*sec)
//{
//	int tmp = *fir;
//	*fir = *sec;
//	*sec = tmp;
//}
//
////void change(int *arr, int length)
////{
////	int* start = arr;
////	int* end = arr + length - 1;
////	while (start < end)
////	{
////		if (*start % 2 == 0)
////		{
////			;
////		}
////		else
////			start++;
////		if (*end % 2 == 1)
////		{
////			;
////		}
////		else
////			end--;
////		swap(start, end);
////	}
////}
////
////int main()
////{
////	int arr[] = { 22, 5, 7, 9, 18, 7, 1, 2, 3, 4 };
////	change(arr, sizeof(arr) / sizeof(arr[0]));
////	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i ++)
////		printf("%d ", arr[i]);
////	system("pause");
////	return 0;
////}
//
//void Function(int *left, int *right)
//{
//	while (left < right)
//	{
//		if (*left % 2 == 1)
//			left++;
//		if (*right % 2 == 0)
//			right--;
//		else
//			swap(left, right);
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,12,67,32,97,100 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Function(arr, arr + len - 1);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}