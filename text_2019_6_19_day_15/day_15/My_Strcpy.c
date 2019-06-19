#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

char *MyStrcpy(char *dest, const char* src)		//把后面的copy到前面
{
	assert(*src != NULL);
	char *p = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	//while (*dest != '\0')
	//	dest++;
	//*dest = '\0';
	return p;
}

int main()
{
	char dest[20] = "abc";
	char *str = "hello";
	MyStrcpy(dest, str);
	printf("%s", dest);
	system("pause");
	return 0;
}