#include<stdio.h>
#include<stdlib.h>

int main()
{
	float i;
	float sum = 0.0;
	int j = -1;
	for(i = 1; i <= 100;i++)
	{
		j = j * j;
		sum = sum + j * (1 / i);
	}
	printf("%f ", sum);
	system("pause");
	return 0;
}