#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

void *MyMemmove(void *dest, const void *src, size_t count)
{
	assert(NULL != src && NULL != dest);
	void *ret = dest;
	//char *p = (char *)dest;
	if(((char*) dest < (char*) src) || ((char*)src + count < (char*)dest))
	{
		while (count != 0)
		{
			*(char*)dest = *(char *)src;
			((char *)dest)++;
			((char*)src)++;
			count--;
		}
	}
	else
	{
		while (count != 0)
		{
			*((char*)dest +count - 1) = *((char *)src + count - 1);
			//((char *)dest)--;
			//((char*)src)--;
			count--;
		}
	}
	return ret;
}

int main()
{
	int arr[] = { 0 };
	int arr1[] = {1,2,3,4,5,6,7,8,9};
	printf("%s", MyMemmove(arr1+2,arr1,16));
	system("pause");
	return 0;
}