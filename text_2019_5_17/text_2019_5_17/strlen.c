//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
////·ÇµÝ¹é
////int Strlen(char* string)
////{
////	int number = 0;
////	while (*string != '\0')
////	{
////		string++;
////		number++;
////	}
////	return number;
////}
////int main()
////{
////	printf("input the string\n");
////	char* string;
////	string = (char *)malloc(sizeof(char));
////	scanf("%s", string);
////	printf("the number is :%d\n", Strlen(string));
////	system("pause");
////	return 0;
////}
//
////µÝ¹é
//
//int Strlen(char* string)
//{
//	if (*string == '\0')
//		return 0;
//	else
//		return Strlen(string+1)+1;
//}
//int main()
//{
//	printf("input the string\n");
//	char* string;
//	string = (char *)malloc(sizeof(char));
//	scanf("%s", string);
//	printf("the number is :%d\n", Strlen(string));
//	system("pause");
//	return 0;
//}
