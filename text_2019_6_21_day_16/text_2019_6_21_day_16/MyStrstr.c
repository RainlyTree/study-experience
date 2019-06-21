//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//char *MyStrstr(const char* str1, const char* str2)   //查找str1中str2 的位置
//{
//	assert(*str1 != NULL && *str2 != NULL);
//	const char *q = str2;
//	const char *p = str1;
//	while (*str1 != '\0')
//	{
//		str1 = p;
//		while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		if (*str1 == '\0')
//		{
//			return NULL;
//		}
//		if (*str2 == '\0')
//		{
//			return p;
//		}
//		p++;
//		str2 = q;
//	}
//	return NULL;
//}