//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//void print_even_digits(unsigned int number)
//{
//	int count = 0;
//	int arr[32] = { 0 };
//	int i = 0;
//	while (number)
//	{
//		arr[i++] = number % 2;
//		number = number / 2;
//		count++;
//	}
//	if (0 == (count % 2))
//	{
//		printf("偶数位:\n");
//		for(i = count - 1; i >= 0; i = i - 2)
//		{
//			printf("%d", arr[i]);
//		}
//		printf("\n");
//		printf("奇数位:\n");
//		for (i = count - 2; i >= 0; i = i - 2)
//		{
//			printf("%d", arr[i]);
//		}
//	}
//	else
//	{
//		printf("偶数位:\n");
//		for (i = count - 2; i >= 0; i = i - 2)
//		{
//			printf("%d", arr[i]);
//		}
//		printf("\n");
//		printf("奇数位:\n");
//		for (i = count - 1; i >= 0; i = i - 2)
//		{
//			printf("%d", arr[i]);
//		}
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int number = 0;
//	printf("input the number :\n");
//	scanf("%d", &number);
//	print_even_digits(number);
//	system("pause");
//	return 0;
//}