#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	for(i = 0;i < 6;i++) //上半部分
	{
		for (j = 0; j < 6 - i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	 
	for (i = 6; i >= 0; i--) //下半部分  上下对称
	{
		for (j = 0; j < 6-i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}