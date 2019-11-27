#include<stdio.h>         10个员工
#include<string.h>
#define N 10
void input(int num[],char name[N][8])
{
	int i;
  for (i=0;i<N;i++)
   {
	  printf("input NO.: ");
      scanf("%d",&num[i]);
      printf("input name: ");
	  scanf("%s",name[i]);
   }
 }

void paixu(int num[],char name[N][8])
 { 
	int i,j,min,templ;
    char temp2[8];
    for(i=0;i<N-1;i++)
	{
	    for(j=0;j<N-1-i;j++)
		    if(num[j]>num[j+1])
			{
				templ=num[j];
				num[j]=num[j+1];
				num[j+1]=templ;
				strcpy(temp2,name[j]);
				strcpy (name[j],name[j+1]);
				strcpy(name[j+1],temp2);
			}
	}
    printf("\n result:\n");
    for (i=0;i<N;i++)
       printf("\n %5d%10s",num[i],name[i]);
 }

void search(int n,int num[],char name[N][8])
{
	int min,max,mid,other,sign;
	min=0;                                  //下限
	max=N-1;                                //上限
	other=0;                                //是否合理
	sign=1;                                 //终止变量
	if ((n<num[0])||(n>num[N-1]))
           other=-1;
     while((sign==1) && (min<=max))
	 {
		 mid=(max+min)/2;
		 if(n==num[mid])
		 {
			 other=mid;
			 printf("NO. %d , his name is %s.\n",n,name[other]);
			 sign=-1;
		 }
		 else
			 if(n<num[mid])
				 max=mid-1;
			 else
				 min=mid+1;
	 }
	 if (sign==1 ||other==-1)
		  printf("%d not been found.\n",n);
}
int main()
{
	void input(int num[],char name[][8]);
    void paixu(int num[],char name[][8]);
    void search(int n,int num[],char name[][8]);
    int num[N],number,flag=1,c;
    char name[N][8];
    input(num,name);
    paixu(num,name);
    while (flag==1)
       {
		printf("\ninput number to look for:");
        scanf("%d",&number);
        search(number,num,name);
        printf("continue ot not(Y/N)?");
        getchar();
        c=getchar();
        if (c=='N'||c=='n')
        flag=0;
       }
        return 0;
}