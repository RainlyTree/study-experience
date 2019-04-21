#include<stdio.h>
#include<stdlib.h>
int main() 
{
	int i;
	int j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++)
			printf("%d*%d=%-2d \t", i, j, i*j);   // 2d 进行右对齐 -2d  进行左对齐
		printf("\n");
	}
	system("pause");
	return 0;
}