//#define _crt_secure_no_warnings 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//int count_one_bits(unsigned int value) //����Ҫ�ж�%2
//{
//	int count = 0;
//	while (value != 0)
//	{
//		value = value & (value - 1);
//		count++;
//	}
//	return count;
//}
//
//int count_one_bits(unsigned int value)  //һ��Ҫ�ж�%2
//{
//	int count = 0;
//	while (value != 0)
//	{
//		if (value % 2 == 1)
//		{
//			count++;
//		}
//		//value = value >> 1;
//		value = value / 2;
//	}
//	return count;
//}
//
//int main()
//{
//	int value = 0;
//	printf("input the number :");
//	scanf("%d", &value);
//	printf("one binary is : %d\n", count_one_bits(value));
//	system("pause");
//	return 0;
//}