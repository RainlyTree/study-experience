#include<stdio.h>
int main()
{
	int max(int x,int y);
		int a,b,c,d;
		scanf("%d %d %d",&a,&b,&c);
d=max(a,b);
d=max(c,d);
printf("max=%d\n",d);
return 0;
}
int max(int x,int y)
{
	int z;
	if(x>y)z=x;
	else z=y;
	return(z);
}                                  //第一种

/*#include<stdio.h>
int main()
{
	int max(int x,int y,int z);
	int a,b,c,d;
scanf("%d %d %d",&a,&b,&c);
d=max(a,b,c);
printf("max=%d\n",d);
return 0;
}
int max(int x,int y,int z)
{
	int u;
	if(x>y)u=x;
	else u=y;
	if(u>z)u=u;
	else u=z;
	return(u);
}*/                               //第二种