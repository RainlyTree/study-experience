//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//int main()
//{
//	int ans = 0;    //目标数字
//	int no = 0;     //读取数字
//	const int MAX_stage = 10;    //最多可以输入的次数
//	int remain = MAX_stage;
//
//	srand((unsigned int)time(NULL));               //生成随机数种子
//	ans = rand() % 1000;         //生成0-999之间的数
//
//	printf("猜  0 ~ 999 之间的数字\n");
//	do
//	{
//		printf("还剩下%d次机会：", remain);
//		// %d 获取数字 其他的直接跳过 到非数字结束
//		scanf("%d", &no);                         //如果没有getchar()会因为输入字母死循环
//		//getchar();                                //防止因为输入字母死循环
//		while ('\n' != getchar());                //保证多个字母输入，将字母全部剔除
//		remain--;								  //一个getchar只会防止一个字母，多个字母会多次循环。
//		if (no > ans)
//			printf("\a再小一点\n");
//		else if (no < ans)
//			printf("\a再大一点\n");
//	} while (no != ans && remain > 0);
//
//	if (no != ans)
//		printf("答案是:%d", ans);
//	else
//	{
//		printf("回答正确");
//		printf("使用了%d次猜中了", MAX_stage - remain);
//	}
//	system("pause");
//	return 0;
//}