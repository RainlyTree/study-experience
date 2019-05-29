//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
////ÕÒµ¥¶ÀµÄÊý×Ö
//int find_single(int arr[],int len)
//{
//		int x = 0;
//		int mem = arr[0];
//		int i = 0;
//		for (i = 1; i < len; i++)
//		{
//			mem = mem ^ arr[i];
//		}
//		return mem;
//}
//
//
//int main()
//{
//	int len = 0;
//	int arr[10] = { 1,3,2,5,5,3,2,7,1 };
//	len = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", find_single(arr, len));
//	system("pause");
//	return 0;
//}