//#define _crt_secure_no_warnings 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//unsigned int reverse_bit(unsigned int value)
//{
//	unsigned int sum = 0;
//	int i = 0;
//	unsigned int tep = 0;
//	for(i = 0; i < 32; i++)
//	{
//		sum = sum << 1;
//		tep = value & 1;
//		sum = sum + tep;
//		value = value >> 1;
//	}
//	return sum;
//}
//
//int main()
//{
//	int number = 0;
//	printf("input the number:");
//	scanf("%d", &number);
//	printf("反向输出值: %u\n", reverse_bit(number));      //无符号整数%u
//	system("pause");
//	return 0;
//}