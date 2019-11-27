#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



#if 0
int main()
{
	int a = 4;
	printf("%d", ++(a++));
	system("pause");
	return 0;

}


int main()
{
	unsigned int a = 0xFFFFFFF7;
	unsigned char i = (unsigned char)a;
	char *b = (char*) &a;
	printf("%08x %08x", i, *b);
	system("pause");
	return 0;
}


int main()
{
	int a = 10;
	int b = 20;
	//const int *p = &a;			//const修饰 * 解引用不能改变
	//int const *p = &a;
	int *const p = &a;				//修饰 p  p不能改变
	p = &b;
	*p = 99;
}

typedef struct student
{
	char name[20];
	int age;
	int id;
	char sex[10];
}STU;

int main()
{
	return 0;
}

int main()
{
	int arr[10] = {1,3,2,5,5,3,2,7,1,9};
	int x = 0;
	int y = 0;
	int mem = arr[0];
	int mark = 1;
	int i = 0;
	for (i = 1; i < 10; i++)
	{
		mem = mem ^ arr[i];
	}
	while (((mem >> 1)&1) != 1)
	{
		mem = mem / 2;
		mark++;
	}
	for (i = 0; i < 10; i++)
	{
		if (((arr[i] >> mark)&1) == 0)
		{
			x = x ^ arr[i];
		}
		else
		{
			y = y ^ arr[i];
		}
	}
	printf("%d %d", x, y);
	system("pause");
	return 0;
}
#endif