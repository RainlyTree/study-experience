#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define LEN sizeof(struct student)           //�ռ��С
struct student
{
	long num;                                //ѧ��
	float score;                             //�ɼ� 
	struct student *next;
};
	struct student *head;
int n=0;
struct student *creat()                      //������̬����
{
	struct student *head;
	struct student *p1,*p2;
	n=0;
	p1=p2=(struct student *)malloc(LEN);     //����ռ�
	scanf("%ld %f",&p1->num,&p1->score);  //����ѧ��  �ɼ�
	head=NULL;
	while(p1->num!=9999)                        //ѧ��Ϊ 9999 ��ֹ����
	{
		n=n+1;
		if(n==1)  head=p1;                   //��ͷ
		else      p2->next=p1;               //�м䲿��
		p2=p1;
		p1=(struct student *)malloc(LEN);
		scanf("%ld %f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return(head);
}
struct student *sort(struct student *head)                       //����
{
	struct student *p1,*p2,*p3;                   //p1Ϊ��ͷ��p2Ϊ��һ����p3��Ϊ�м�ת��
	p3=(struct student *)malloc(LEN);
	p1=head;
	p2=p1->next;
	while(p1->next!=NULL)                         //���ѭ��
	{
		while(p2!=NULL)                     //�ڲ�ѭ������һ������������������д�С�Ƚ�
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
void print(struct student *head)                                    //���
{
	struct student *p;
	printf("\nNOW,There %d records are:\n",n);                     //���ѧ������
	p=head;
	if(head!=NULL)
		do
		{
			printf("%ld %5.1f\n",p->num,p->score);
			p=p->next;

		}while(p!=NULL);
}
struct student *search(struct student *head)    //���Һ���
{
	struct student *p1,*p2;
	int a;
	p1=p2=head;
		printf("������Ҫ���ҵ�ѧ��");
		scanf("%d",&a);
	while(p1->num!=a&&p1->next!=NULL)                        //�������������һ����Ϊ��
	{
		p2=p1;  p1=p2->next;
	}
	if(p1->num==a)
		printf("ѧ��:%ld �ɼ�:%f",p1->num,p1->score);
	else
		printf(" ���޴���!");
	return 0;
}
struct student *Slice(struct student *head)    //ɾ������
{
	struct student *p1,*p2;
	int a;
	printf("������Ҫɾ����ѧ��");
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
	else printf("���޴���!");
	n=n-1;
	return(head);
}
struct student *inhert(struct student *head)    //���뺯��
{
	struct student *p1,*p2,*p0;
	p1=p2=head;
	p0=(struct student *)malloc(LEN);
	scanf("%ld %f",&p0->num,&p0->score);
	while(p1->num<p0->num&&p1->next!=NULL)
	{
		p2=p1; p1=p1->next;
	}
	if(p1->num>=p0->num)                                            //���봦��
		if(p1==head)                                                //�����ڿ�ͷ
		{
			head=p0;  p0->next=p1;
		}
		else                                                        //������ĩβ
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
/*��ѧ����Ϣд���ļ�  */
void IO_WriteInfo()
{  
     FILE *fp;  
     if ((fp=fopen("Database.txt","wb"))==NULL)  
     {  
         printf("���ܴ��ļ�!\n");  
         return;  
	 }
	 do
	 {
         if (fwrite(head,sizeof(struct student),1,fp)!=1)  
         {  
              printf("д���ļ�����!\n");  
         }
		 head=head->next;
	 }while(head!=NULL);
     fclose(fp);   
}
/*��ѧ����Ϣ���ļ�����*/
  void IO_ReadInfo()
{  
     FILE *fp;  
     if ((fp=fopen("Database.txt","rb"))==NULL)  
     {  
         printf("���ܴ��ļ�!\n"); 
         return;  
     } 
    /* while(!feof(fp))                  //һֱ��ȡ֪���ļ�β����  
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
	printf("-------------ѧ����Ϣ����ϵͳ---------------\n");
	printf("\t\t0. ѧ����Ϣ¼��\n");
    printf("\t\t1. ѧ����Ϣ���\n");
    printf("\t\t2. ѧ����Ϣ��ѯ\n");
    printf("\t\t3. ѧ����Ϣɾ��\n");
    printf("\t\t4. ѧ����Ϣ����\n");
    printf("--------------------------------------------\n");
	printf("����������ѡ��(1~~4): ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 0:  head=creat();head=sort(head); break;
    case 1:  print(head);  break;
	case 2:  search(head); break;
	case 3:  Slice(head);  break;
	case 4:  inhert(head);head=sort(head); break;
	}
	printf("�Ƿ�Ҫ������ѯ0/1");
	scanf("%d",&a);
	}
	IO_WriteInfo();
}
