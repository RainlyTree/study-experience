//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//int main()
//{
//	int ans = 1564654;    //目标数字
//	int no = 0;     //读取数字
//	const int MAX_stage = 3;    //最多可以输入的次数
//	int remain = MAX_stage;
//
//	printf("请输入密码\n");
//	do
//	{
//		printf("还剩下%d次机会：", remain);
//		scanf("%d", &no);
//		remain--;
//	} while (no != ans && remain > 0);
//
//	if (no != ans)
//		printf("答案是:%d \n", ans);
//	else
//	{
//		printf("回答正确");
//		printf("使用了%d次猜中了", MAX_stage - remain);
//	}
//	system("pause");
//	return 0;
//}