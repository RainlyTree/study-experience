#include<stdio.h>
int main()
{
	int a[11],i,t;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	    scanf("%d",a[10]);
	if(a[i]>a[10])
	{
		a[i]=t;
		a[i]=a[10];
		a[11]=t;
	}
		printf("%d",a[i]);
	}
	return 0;
}