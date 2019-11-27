#include<time.h>
#include<stdio.h>
#include<stdlib.h>                   //内部定义了RAND_MAX==32767 且最小32767    //#define RAND_MAX 100000
int main()
{
    int retry;                      /*再次运行*/      //因为类型为int型 所以取值范围是 -32768 ~~~ 32767
    srand(time(NULL));                  /* srand选择rand中伪随机数序列      根据当前时间设定随机数的种子*/
    printf("在这个编程环境中能够生成0~%d的随机数.\n",RAND_MAX);
    do{
        printf("\n生成了随机数%d.\n",rand());
        printf("在运行一次？。。。(0)否（1）是：");
        scanf("%d",&retry);
    }while(retry==1);
    return 0;
}