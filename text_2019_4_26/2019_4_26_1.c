#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	for(i = 0;i < 6;i++) //�ϰ벿��
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
	 
	for (i = 6; i >= 0; i--) //�°벿��  ���¶Գ�
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