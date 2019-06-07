#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

int my_len(char *arr)
{
	assert(arr);
	int len = 0;
	while (*arr++)
		{
			len++;
		 }
	return len;
}

void my_Reversal(char *start,char *end)		//完全反转
{
	char tem;
	while (start < end)
	{
		tem = *start;
		*start = *end;
		*end = tem;
		start++;
		end--;
	}
}

void quire_Rve(char arr[])
{
	assert(arr);
	my_Reversal(arr,arr + my_len(arr) - 1);
	while (*arr)
	{
		char *tmp = arr;
		while ((*arr != ' ') && (*arr != '\0'))
		{
			arr++;
		}
		my_Reversal(tmp, arr - 1);
		if (*arr == ' ')
		{
			arr++;
		}
	}
}

int main()
{
	char arr[] = "i am a student";
	quire_Rve(arr);
	printf("%s", arr);
	system("pause");
	return 0;
}