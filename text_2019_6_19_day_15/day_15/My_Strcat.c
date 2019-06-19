//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<assert.h>
//
//char *MyStrcat(char *dest, const char *str)     //将一个字符串放在另一个字符串后面
//{
//	assert(dest != NULL);
//	assert(str != NULL);
//	char *p = dest;
//	while (*dest != '\0')				//防止写成dest != '\0'
//		dest++;
//	while (*(dest++) = *(str++))
//	{
//		;
//	}
//	return p;
//}
//
//int main()
//{
//	char dest[20] = "hello";
//	char *str = "ddd";
//	MyStrcat(dest, str);
//	printf("%s", dest);
//	system("pause");
//	return 0;
//}