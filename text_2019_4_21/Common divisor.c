#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int first_way(int i, int j);
	int fir_number = 0;
	int sec_number = 0;
	scanf(" %d %d", &fir_number, &sec_number);
	first_way(fir_number, sec_number);
	system("pause");
	return 0;
}

int first_way(int i, int j)    //相减法算公约数
{
	while (i != j)
	{
		while(i < j)
			j = j - i;
		while (j < i)
			i = i - j;
	}
	printf("%d ", i);
	return 0;
}