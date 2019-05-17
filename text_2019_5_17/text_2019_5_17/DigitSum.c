#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int DigitSum(int n)
{
	if (n <= 0)
		return 0;
	else
	{
		return DigitSum(n / 10)+(n % 10);
	}
}
int main()
{
	int number = 0;
	printf("input the number:");
	scanf("%d", &number);
	printf("%d\n", DigitSum(number));
	system("pause");
	return 0;
}