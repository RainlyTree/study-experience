#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int prime_number(int number)
{
	int j = 0;
		for (j = 2; j <= sqrt(number); j++)
		{
			if (number%j == 0)
				break;
		}
		if (j > sqrt(number))
			printf("%d is prime number\n", number);
		else
			printf("%d is not prime number\n", number);
	return 0;
}

int main()
{
	int number = 0;
	printf("input a number\n");
	scanf("%d", &number);
	prime_number(number);
	system("pause");
	return 0;
}