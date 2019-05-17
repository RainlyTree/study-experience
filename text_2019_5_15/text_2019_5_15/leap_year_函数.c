#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int leap_year(int year) 
{
		if (year % 400 == 0)                   //陷阱：：：若先判断 %4 会无法进入 %400
			printf("%d is leap year\n", year);
		else if (year % 4 == 0 && year % 100 != 0)
			printf("%d is leap year\n", year);
		else
			printf("%d is not leap year\n", year);
	return 0;
}

int main()
{
	int year = 0;
	printf("input a year\n");
	scanf("%d", &year);
	leap_year(year);
	system("pause");
	return 0;
}
