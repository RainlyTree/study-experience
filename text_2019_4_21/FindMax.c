#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int number[10] = { 0 };
	int max = 0;
	int i = 0;
	for (i = 0; i < 10; i++) 
	{
		scanf("%d ", &number[i]);
	}
	//printf("\n");
	for (i = 0; i <= 9; i++)
	{
		if ( number[i] > max )
			max = number[i];
	}
	printf("%d ", max);
	system("pause");
	return 0;
}