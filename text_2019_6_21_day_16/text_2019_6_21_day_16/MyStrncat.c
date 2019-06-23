#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *MyStrncat(char *dest, const char *src, int n)			//	没有判断是否容得下
{
	assert(*src != NULL);
	char *p = *dest;
	while (*dest != '\0')
		dest++;
	while (n != 0)
	{
		*(dest++) = *(src++);
		n--;
	}
	return p;
}
