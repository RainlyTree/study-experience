/*#include<stdio.h>
#define LINE 30
int main()
{
	int i,j;
	for(i=0;i<LINE;i++)
	{
		for(j=0;j<(LINE-i);j++)
		{
			printf(" ");
		}
		for(j=0;j<2*i+1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
		return 0;
}*/

/*#include<stdio.h>
#define LINE 60
int main()
{
	int i,j;
    for(i=0;i<LINE;i++)
	{
		if(i<=30);for(j=0;j<(LINE-i);j++)
		{
			printf(" ");
		}
		     for(j=0;j<2*i+1;j++)
		{
			printf("*");
		}
		else for(j=0;j<(LINE-30);j++)
			{
				printf(" ");
			}
				for(j=0;j<(LINE-i);j++)
				{
				printf("*");
				}
		printf("\n");
	}
		return 0;
}*/


/*#include<stdio.h>
#define LINE 15
int main()
{
	int i,j;
	for(i=0;i<=LINE;i++)
	{
		for(j=0;j<=(LINE-i);j++)
		{
			printf(" ");
		}
		for(j=0;j<2*i+1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i=LINE-1;i>=0;i--)
	{
		for(j=0;j<=(LINE-i);j++)
		{
			printf(" ");
		}
		for(j=0;j<2*i+1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
*/               //µÚÒ»ÖÖ
#include<stdio.h>
#define LINE 31
int main()
{
    int i,j;
    int n;
    for (i = 0; i < LINE; i++)
    {
        if (i <= LINE / 2)
            n = i;
        else
            n = LINE-i-1;
        for (j=0;j<(LINE/2-n); j++)
		{
            printf(" ");
		}
        for (j=0;j<2*n+1;j++)
		{
            printf("*");
		}
        printf("\n");
    }

    return 0;
}