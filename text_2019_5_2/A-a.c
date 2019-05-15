#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ch;
	printf("ÊäÈëÒ»¸ö×Ö·û\n");
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
<<<<<<< HEAD
			printf("%c ", ch - 32);
		else if (ch >= 'A' && ch <= 'Z')
			printf("%c ", ch + 32);
=======
			printf("%c \n", ch - 32);
		else if (ch >= 'A' && ch <= 'Z')
			printf("%c \n", ch + 32);
>>>>>>> 634ba00e030601e4cec9467f3e449aa7e4dc8391
		else if (ch >= '0' && ch <= '9')
			;
	}
	printf("\n");
	system("pause");
	return 0;
}