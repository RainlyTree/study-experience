#include<stdio.h>
#define MAX 10
int main()
{
	int i,j,n=MAX;
	int array[MAX][MAX]={0};

	for(i=0;i<n;i++)
	{
		array[i][0]=1;
		array[i][i]=1;
	}
	//打印二维数组中的三角形
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
			printf("%5d",array[i][j]);

		printf("\n");
	}
}

