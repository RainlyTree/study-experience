#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//递归方式
int Factorial(int number)
{
	if (number <= 1)
		return 1;
	else
		return number * Factorial(number - 1);
}
int main()
{
	int number = 0;
	printf("input the number :");
	scanf("%d", &number);
	printf("%d", Factorial(number));
	system("pause");
	return 0;
}

//非递归方式
int Factorial(int number)
{
	int i = 0;
	int sum = 1;
	for (i = 1; i <= number; i++)
		sum = sum * i;
	return sum;
}
int main()
{
	int number = 0;
	printf("input the number :");
	scanf("%d", &number);
	printf("%d", Factorial(number));
	system("pause");
	return 0;
}