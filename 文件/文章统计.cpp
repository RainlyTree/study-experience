#include<stdio.h>
int main()
{
	char a[3][5];
	int n,b,c,d,e,i,j;
	n=0;
	b=0;
	c=0;
	d=0;
	e=0;
	printf("put:\n");
	for(i=0;i<3;i++)
		gets(a[i]);
	for(i=0;i<3;i++)
		for(j=0;j<5;j++)
		{
			if('A'<=a[i][j]&&a[i][j]<='Z')
				n++;
			else
			if('a'<=a[i][j]&&a[i][j]<='z')
				b++;
			else
			if('0'<=a[i][j]&&a[i][j]<='9')
				c++;
			else
			if(a[i][j]==' ')
			    d++;
			else
				e++;
		}
		printf("��д��ĸ=%d\nСд��ĸ=%d\n����=%d\n�ո�=%d\n����=%d\n",n,b,c,d,e);
		return 0;
}
