#include<time.h>
#include<stdio.h>
#include<stdlib.h>                   //�ڲ�������RAND_MAX==32767 ����С32767    //#define RAND_MAX 100000
int main()
{
    int retry;                      /*�ٴ�����*/      //��Ϊ����Ϊint�� ����ȡֵ��Χ�� -32768 ~~~ 32767
    srand(time(NULL));                  /* srandѡ��rand��α���������      ���ݵ�ǰʱ���趨�����������*/
    printf("�������̻������ܹ�����0~%d�������.\n",RAND_MAX);
    do{
        printf("\n�����������%d.\n",rand());
        printf("������һ�Σ�������(0)��1���ǣ�");
        scanf("%d",&retry);
    }while(retry==1);
    return 0;
}