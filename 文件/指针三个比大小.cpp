#include<stdio.h>
int main()
{
	void max(int *p1,int *p2);
	int a,b,c,*p1,*p2,*p3,*p;
	printf("请输入3个数字\n");
	scanf("%d%d%d",&a,&b,&c);
	p1=&a;p2=&b;p3=&c;
	if(*p1>*p2)
		max(p1,p2);
	if(*p2>*p3)
		max(p2,p3);
	if(*p1>*p3)
		max(p1,p3);
	printf("由小到大排列是\n");
	printf("%d,%d,%d",*p1,*p2,*p3);
	return 0;
}
void max(int *p1,int *p2)
{
	int x;
	x=*p1;
	*p1=*p2;
	*p2=x;
}

