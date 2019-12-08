#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
//float
//average(int n_values, ...)
//{
//	va_list	var_arg;
//	int count;
//	float sum = 0;
//
//	va_start(var_arg, n_values);
//	for (count = 0; count < n_values; count += 1)
//	{
//		sum += va_arg(var_arg, int);
//	}
//	va_end(var_arg);
//
//	return sum / n_values;
//}

//token²âÊÔ
#if 0
void 
print_tokens(char *line)
{
	static char whitespace[] = "\t\f\r\v\n";
	char *token;
	for (token = strtok(line, whitespace); token != NULL; token = strtok(NULL, whitespace);)
	{
		printf("Next token is %s\n",token);
	}
}

int main()
{
	char arr[] = "fjhjk\tshdjkha\rusyrn";
	print_tokens(arr);
	system("pause");
	return 0;
}
#endif