#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC

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