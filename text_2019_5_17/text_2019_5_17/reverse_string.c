#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int reverse_string(char* string)
{
	if (*string == '\0')
		//printf("%c", *string);  多输出一个空格
		return 0;
	else
	{
		reverse_string(++string);
		printf("%c", *(--string));
	}
	return 0;
}
int main()
{
	char* string="sahdfkhgafkiugwlfdhk";
	reverse_string(string);
	system("pause");
	return 0;
}