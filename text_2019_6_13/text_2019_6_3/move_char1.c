#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC

void left_move(char *str, int k)
{
	assert(str != NULL);
	int i = 0;
	for (i = 0; i < k; i++)
	{
		char tmp = *str;
		int j = 0;
		while (*(str + j + 1) != '\0')
		{
			*(str + j )= *(str + j + 1);
			j++;
		}
		*(str + j) = tmp;
	}
}

int is_left_move(char *arr, const char *p)
{
	assert(arr != NULL);
	assert(p != NULL);
	int number = strlen(arr);
	int count = 0;
	while (number != 0)
	{
		if (! strcmp(arr, p))
		{
			break;
		}
		left_move(p, 1);
		count++;
		number--;
	}
	if (!strcmp(arr, p))
		return count;
	else
		return 0;
}

int main()
{
	char str[] = "ABCDA";
	char *str1 = "ABCDD";
	printf("%d", is_left_move(str1, str));
	system("pause");
	return 0;
}