#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int sum = 0;
	scanf("%d", &i);
	sum = 5 * i + 4 * 10 * i + 3 * 100 * i + 2 * 1000 * i + 10000 * i;
	printf(" %d ", sum);
	system("pause");
	return 0;
}