#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int first = 0;                普通转换
//	int second = 0;
//	int tem = 0;
//	scanf("%d %d",&first ,&second);
//	tem = first;
//	first = second;
//	second = tem;
//	printf("%d %d ", first, second);
//	system("pause");
//	return 0;
//}

//int main()                    //使用指针
//{
//	int first = 0;
//	int second = 0;
//	scanf("%d %d", &first, &second);
//	swap(&first, &second);
//	printf("%d ,%d ", first, second);
//	system("pause");
//	return 0;
//}
//
//int swap(int *i, int *j)
//{
//	int tem = 0;
//	tem = *i;
//	*i = *j;
//	*j = tem;
//	return 0;
//}

int main()                  //不使用临时变量
{
	int first = 0;
	int second = 0;
	scanf(" %d %d", &first, &second);
	//first = second + first;                   //加法性质 两个可以由和与另一个数确定
	//second = first - second;
	//first = first - second;

	first = second ^ first;                  // a ^ b ^ b = a;
	second = second ^ first;
	first = first ^ second;

	printf("%d %d", first, second);
	system("pause");
	return 0;
}