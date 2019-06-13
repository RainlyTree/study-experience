//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<assert.h>
//
////实现一个函数，可以左旋字符串中的k个字符。
////ABCD左旋一个字符得到BCDA
////ABCD左旋两个字符得到CDAB
//
//void left_move(char *str, int k)
//{
//	assert(str != NULL);
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		char tmp = *str;
//		int j = 0;
//		while (*(str + j + 1) != '\0')
//		{
//			*(str + j )= *(str + j + 1);
//			j++;
//		}
//		*(str + j) = tmp;
//	}
//}
//
//int main()
//{
//	int number = 0;
//	printf("input the number :");
//	scanf("%d", &number);
//	char str[] = "ABCD"; //若这里是指针 函数会出问题
//	left_move(str, number);
//	printf("%s", str);
//	system("pause");
//	return 0;
//}