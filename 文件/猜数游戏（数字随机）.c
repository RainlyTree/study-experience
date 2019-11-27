#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int no;                          /*读取的数字*/
    int ans;                         /*目标数字*/
    const  int max_stage=10;         /*最多可以输入的次数*/         /*const使得max_stage值无法改变*/
    int ramain=max_stage;            /*还可以输入的次数*/
    srand(time(NULL));               /*设定随机数的种子*/
    ans=rand()%1000;                 /*生成一个随机数*/
    printf("请猜一个0~999的整数。\n\n");
    do{
        printf("还剩下%d次机会。是多少呢：",remain);
        scanf("%d",&no);
        remain--;
        if(no>ans)
            printf("\a再小一点。\n");
        else if(no<ans);
            printf("\a再大一点。\n");
    }while(no!=ans&&remain>0);
    if(no!-ans)
        printf("\a很遗憾。正确答案是%d。\n",ans);
    else{
        printf("回答正确。\n");
        printf("您用了%d次机会猜中了。\n",max_stage-remain);
    }
    return 0;
}