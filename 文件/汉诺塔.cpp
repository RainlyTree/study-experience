/*#include<stdio.h>
int main()
{
	int age(int n);
	printf("NO.5,age:%d\n",age(5));
	return 0;
}
int age(int n)
{
	int c;
	if(n==1)
		c=10;
	else
		c=age(n-1)+2;
	return (c);
}*/



/*#include<stdio.h>
int main()
{
	void hanoi(int n,char one,char two,char three);
	int m;
	printf("input the number of diskes:");
	scanf("%d",&m);
	printf("The step to move %d diskes:\n",m);
	hanoi(m,'A','B','C');
	return 0;
}

void hanoi(int n,char one,char two,char three)
{
	void move(int n,char x,char y);
	if(n==1)
		move(n,one,three);
	else
	{
		hanoi(n-1,one,three,two);
		move(n,one,three);
		hanoi(n-1,two,one,three);
	}
}
void move(int n,char x,char y)
{
	printf("%d:%c-->%c\n",n,x,y);
}*/
