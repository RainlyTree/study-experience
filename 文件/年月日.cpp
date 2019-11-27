#include<stdio.h>
int main()
{
      int nian(int n);
      int i, num, year, month, day;
      int d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
      while (true)
		{
           num = 0;
           scanf("%d%d%d",&year,&month,&day);
           if (nian(year)== 0) d[1] = 29;
           for (i = 0; i < month - 1; i++) num += d[i];
           num += day;
           printf("%d",num);
		}
		return 0;
}
int nian(int n)
{
	int flat;
	if(n%4==0)
	{
		if(n%100==0)
		{
			if(n%400==0)
				flat=1;
			else
				flat=0;
		}
		else
			flat=1;
	}
	else
		flat=0;
			return 0;
}
