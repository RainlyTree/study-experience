#include<stdio.h>
int main()
{
	int *p,a[3][3],i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	}
	p=&a[0][0];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d",*(*(p+j)+i));
		printf("\n");
	}
	return 0;
}