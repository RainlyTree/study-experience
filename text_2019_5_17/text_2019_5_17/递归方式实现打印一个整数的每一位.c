#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Everynumber(int n)
{
	if (n <= 0)
		return 0;
	else
	{
		Everynumber(n / 10);
		printf("%d ", n % 10);
	}
	return 0;
}
int main()
{
	int number = 0;
	printf("input the number:");
	scanf("%d", &number);
	Everynumber(number);
	system("pause");
	return 0;
}