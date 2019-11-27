#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define LEN sizeof(struct student)           //空间大小
struct student
{
	long num;                                //学号
	float score;                             //成绩 
	struct student *next;
};
	struct student *head;
int n=0;
struct student *creat()                      //建立动态链表
{
	struct student *head;
	struct student *p1,*p2;
	n=0;
	p1=p2=(struct student *)malloc(LEN);     //申请空间
	scanf("%ld %f",&p1->num,&p1->score);  //输入学号  成绩
	head=NULL;
	while(p1->num!=9999)                        //学号为 9999 终止输入
	{
		n=n+1;
		if(n==1)  head=p1;                   //开头
		else      p2->next=p1;               //中间部分
		p2=p1;
		p1=(struct student *)malloc(LEN);
		scanf("%ld %f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return(head);
}
struct student *sort(struct student *head)                       //排序
{
	struct student *p1,*p2,*p3;                   //p1为开头，p2为下一个，p3作为中间转换
	p3=(struct student *)malloc(LEN);
	p1=head;
	p2=p1->next;
	while(p1->next!=NULL)                         //外层循环
	{
		while(p2!=NULL)                     //内层循环，将一个数与后面所有数进行大小比较
		{
			if(p2->num<p1->num)
			{
				p3->num=p1->num;    p3->score=p1->score;
				p1->num=p2->num;    p1->score=p2->score;
				p2->num=p3->num;    p2->score=p3->score;
			}
			p2=p2->next;
		}
		p1=p1->next;
		p2=p1->next;
	}
	return(head);
}
void print(struct student *head)                                    //输出
{
	struct student *p;
	printf("\nNOW,There %d records are:\n",n);                     //输出学生总数
	p=head;
	if(head!=NULL)
		do
		{
			printf("%ld %5.1f\n",p->num,p->score);
			p=p->next;

		}while(p!=NULL);
}
struct student *search(struct student *head)    //查找函数
{
	struct student *p1,*p2;
	int a;
	p1=p2=head;
		printf("请输入要查找的学号");
		scanf("%d",&a);
	while(p1->num!=a&&p1->next!=NULL)                        //两个不相等且下一个不为空
	{
		p2=p1;  p1=p2->next;
	}
	if(p1->num==a)
		printf("学号:%ld 成绩:%f",p1->num,p1->score);
	else
		printf(" 查无此人!");
	return 0;
}
struct student *Slice(struct student *head)    //删除函数
{
	struct student *p1,*p2;
	int a;
	printf("请输入要删除的学号");
	scanf("%d",&a);
	p2=p1=head;
	while(p1->num!=a&&p1->next!=NULL)
	{
		p2=p1;  p1=p1->next;
	}
	if(p1->num==a)
	{
		if(head==p1) {p1=p1->next,head=p1;}
		else {p2->next=p1->next;}
	}
	else printf("查无此人!");
	n=n-1;
	return(head);
}
struct student *inhert(struct student *head)    //插入函数
{
	struct student *p1,*p2,*p0;
	p1=p2=head;
	p0=(struct student *)malloc(LEN);
	scanf("%ld %f",&p0->num,&p0->score);
	while(p1->num<p0->num&&p1->next!=NULL)
	{
		p2=p1; p1=p1->next;
	}
	if(p1->num>=p0->num)                                            //插入处理
		if(p1==head)                                                //插入在开头
		{
			head=p0;  p0->next=p1;
		}
		else                                                        //插入在末尾
			if(p1->next==NULL)
			{
			     p1->next=p0;  p0->next=NULL;
			}
			else
				{
					p2->next=p0; p0->next=p1;
				}
	n=n+1;
	return(head);
}
/*将学生信息写入文件  */
void IO_WriteInfo()
{  
     FILE *fp;  
     if ((fp=fopen("Database.txt","wb"))==NULL)  
     {  
         printf("不能打开文件!\n");  
         return;  
	 }
	 do
	 {
         if (fwrite(head,sizeof(struct student),1,fp)!=1)  
         {  
              printf("写入文件错误!\n");  
         }
		 head=head->next;
	 }while(head!=NULL);
     fclose(fp);   
}
/*将学生信息从文件读出*/
  void IO_ReadInfo()
{  
     FILE *fp;  
     if ((fp=fopen("Database.txt","rb"))==NULL)  
     {  
         printf("不能打开文件!\n"); 
         return;  
     } 
    /* while(!feof(fp))                  //一直读取知道文件尾结束  
	 {
		 fread(creat,sizeof(struct student),1,fp);  
		 creat=(struct student *)malloc(LEN);
		 printf("%ld %f",creat->num,creat->score);
		 creat=creat->next;
	 }*/
      do
	  {
		fread(head,sizeof(struct student),1,fp);
		printf("%ld %f",head->num,head->score);
		head=head->next;
	  }while(head!=NULL);
     fclose(fp);  
} 
void main()
{
	int choose;
	int a=1;
	IO_ReadInfo();
	while(a==1)
	{
	printf("-------------学生信息管理系统---------------\n");
	printf("\t\t0. 学生信息录入\n");
    printf("\t\t1. 学生信息浏览\n");
    printf("\t\t2. 学生信息查询\n");
    printf("\t\t3. 学生信息删除\n");
    printf("\t\t4. 学生信息插入\n");
    printf("--------------------------------------------\n");
	printf("请输入您的选择(1~~4): ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 0:  head=creat();head=sort(head); break;
    case 1:  print(head);  break;
	case 2:  search(head); break;
	case 3:  Slice(head);  break;
	case 4:  inhert(head);head=sort(head); break;
	}
	printf("是否要继续查询0/1");
	scanf("%d",&a);
	}
	IO_WriteInfo();
}
