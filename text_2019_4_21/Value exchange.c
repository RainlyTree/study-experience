#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int first = 0;                ��ͨת��
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

//int main()                    //ʹ��ָ��
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

int main()                  //��ʹ����ʱ����
{
	int first = 0;
	int second = 0;
	scanf(" %d %d", &first, &second);
	//first = second + first;                   //�ӷ����� ���������ɺ�����һ����ȷ��
	//second = first - second;
	//first = first - second;

	first = second ^ first;                  // a ^ b ^ b = a;
	second = second ^ first;
	first = first ^ second;

	printf("%d %d", first, second);
	system("pause");
	return 0;
}