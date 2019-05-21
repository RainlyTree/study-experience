#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int different_bit(int number, int number1)
{
	int count = 0;
	number = number ^ number1;
	while (number != 0)
	{
		count++;
		number = number & (number - 1);
	}
	return count;
}

int main()
{
	int number = 0;
	int number1 = 0;
	printf("input the number:");
	scanf("%d %d", &number, &number1);
	printf("%d\n", different_bit(number, number1));
	system("pause");
	return 0;
}