#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int arr[] = {1 ,2 ,3 ,4 ,5};
	int arr1[] = {6 ,7 ,8 ,9 ,10};
	int tem = 0;
	for (i = 0; i < 5; i++)
	{
		tem = arr[i];
		arr[i] = arr1[i];
		arr1[i] = tem;
		printf("%-2d %-2d\n", arr[i], arr1[i]);
	}
	system("pause");
	return 0;
}