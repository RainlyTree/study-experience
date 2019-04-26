#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int first_number = 0;
	int secound_number = 0;
	int third_number = 0;
	for (i = 0; i < 999; i++)
	{
		first_number = (i / 100) ; 
		secound_number = (i / 10) % 10;
		third_number = i % 10;
		if (i == (first_number*first_number*first_number + secound_number * secound_number*secound_number + third_number * third_number*third_number))
			printf(" %d \t", i);
	}
	system("pause");
	return 0;
}