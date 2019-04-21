#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int sort(int *i, int *j, int *k);
	int fir = 0;
	int sec = 0;
	int thr = 0;
	scanf("%d %d %d", &fir, &sec, &thr);
	sort(&fir, &sec, &thr);
	printf("%d %d %d", fir, sec, thr);
	system("pause");
	return 0;
}

int sort(int *i, int *j, int *k)
{
	int change = *i;
	if (*j > *i)
	{
		change = *i;
		*i = *j;
		*j = change;
	}
	if (*k > *j)
	{
		change = *k;
		*k = *j;
		*j = change;
	}
	if (*j > *i)
	{
		change = *i;
		*i = *j;
		*j = change;
	}
	return 0;
}