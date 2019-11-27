#include<stdio.h>
int main()
{
    int no;
    int ans=7;
    printf("猜一个1~9的整数。\n\n");
    do{
        scanf("%d",&no);
        if(no>ans)
            printf("\a 再小一点 \n");
        else if(no<ans)
            printf("\a 再大一点 \n");
        else
            printf("回答正确。\n");
    }while(no!=ans);
    return 0;
}