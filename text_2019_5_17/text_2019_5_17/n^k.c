<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n_k(int number, int index)
{
	if(number == 0)
		return 0;
	else
	{
		if (index == 0)
			return 1;
		else
			return number * n_k(number, index - 1);
	}
}

int main()
{
	int number = 0;
	int index = 0;
	printf("input the number and index:");
	scanf("%d %d", &number, &index);
	printf("the final number is %d\n", n_k(number, index));
	system("pause");
	return 0;
}
=======
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//int n_k(int number, int index)
//{
//	if(number == 0)
//		return 0;
//	else
//	{
//		if (index == 0)
//			return 1;
//		else
//			return number * n_k(number, index - 1);
//	}
//}
//
//int main()
//{
//	int number = 0;
//	int index = 0;
//	printf("input the number and index:");
//	scanf("%d %d", &number, &index);
//	printf("the final number is %d\n", n_k(number, index));
//	system("pause");
//	return 0;
//}
>>>>>>> f667580587c8ca35c3998cc49cc227872ae50cc1
