//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<assert.h>
//
////ʵ��һ�����������������ַ����е�k���ַ���
////ABCD����һ���ַ��õ�BCDA
////ABCD���������ַ��õ�CDAB
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
//	char str[] = "ABCD"; //��������ָ�� �����������
//	left_move(str, number);
//	printf("%s", str);
//	system("pause");
//	return 0;
//}