#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

<<<<<<< HEAD
·ÇµÝ¹é
int main()
{
	int fir = 1;
	int sec = 1;
	int next = 0;
	int n = 0;
	printf("input the number:");
	scanf("%d", &n);
	if (n <= 2)
		printf("the number is %d\n", fir);
	else
	{
		for (int i = 2; i < n; i++)
		{
			next = fir + sec;
			fir = sec;
			sec = next;
		}
		printf("the number is %d\n", next);
	}
	system("pause");
	return 0;
}

µÝ¹é
int fibonacci_sequence(int number)
{
	if (number <= 2)
		return 1;
	else
		return fibonacci_sequence(number - 2) +fibonacci_sequence(number - 1);
}
int main()
{
	int n = 0;
	printf("input the number:");
	scanf("%d", &n);
	printf("the number is %d\n", fibonacci_sequence(n));
	system("pause");
	return 0;
}
=======
//·ÇµÝ¹é
//int main()
//{
//	int fir = 1;
//	int sec = 1;
//	int next = 0;
//	int n = 0;
//	printf("input the number:");
//	scanf("%d", &n);
//	if (n <= 2)
//		printf("the number is %d\n", fir);
//	else
//	{
//		for (int i = 2; i < n; i++)
//		{
//			next = fir + sec;
//			fir = sec;
//			sec = next;
//		}
//		printf("the number is %d\n", next);
//	}
//	system("pause");
//	return 0;
//}

//µÝ¹é
//int fibonacci_sequence(int number)
//{
//	if (number <= 2)
//		return 1;
//	else
//		return fibonacci_sequence(number - 2) +fibonacci_sequence(number - 1);
//}
//int main()
//{
//	int n = 0;
//	printf("input the number:");
//	scanf("%d", &n);
//	printf("the number is %d\n", fibonacci_sequence(n));
//	system("pause");
//	return 0;
//}
>>>>>>> f667580587c8ca35c3998cc49cc227872ae50cc1
