#include<stdio.h>
int main()
{
    int no;
    int ans=7;
    printf("��һ��1~9��������\n\n");
    do{
        scanf("%d",&no);
        if(no>ans)
            printf("\a ��Сһ�� \n");
        else if(no<ans)
            printf("\a �ٴ�һ�� \n");
        else
            printf("�ش���ȷ��\n");
    }while(no!=ans);
    return 0;
}