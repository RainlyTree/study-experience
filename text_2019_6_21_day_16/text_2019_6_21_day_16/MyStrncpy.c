#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *MyStrncpy(char *dest, const char* src, int n)		//把后面的copy到前面
{
	assert(*src != NULL);
	char *p = dest;
	while (n != 0 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	//while (*dest != '\0')
	//	dest++;
	//*dest = '\0';
	return p;
}