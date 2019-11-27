#include<stdio.h>
int main()
{
	int x,y,z;
	for(x=0;x<101;x++)
		for(y=0;y<50;y++)
			for(z=0;z<34;z++)
				if(x+2*y+3*z==100)
				{
					printf("x=%d,y=%d,z=%d\n",x,y,z);
				}
				return 0;
}