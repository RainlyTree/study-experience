<<<<<<< HEAD
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//int main()
//{
//	int ans = 1564654;    //Ŀ������
//	int no = 0;     //��ȡ����
//	const int MAX_stage = 3;    //����������Ĵ���
//	int remain = MAX_stage;
//
//	printf("����������\n");
//	do
//	{
//		printf("��ʣ��%d�λ��᣺", remain);
//		scanf("%d", &no);
//		remain--;
//	} while (no != ans && remain > 0);
//
//	if (no != ans)
//		printf("����:%d \n", ans);
//	else
//	{
//		printf("�ش���ȷ");
//		printf("ʹ����%d�β�����", MAX_stage - remain);
//	}
//	system("pause");
//	return 0;
//}
=======
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int ans = 1564654;    //Ŀ������
	int no = 0;     //��ȡ����
	const int MAX_stage = 3;    //����������Ĵ���
	int remain = MAX_stage;

	printf("����������\n");
	do
	{
		printf("��ʣ��%d�λ��᣺", remain);
		scanf("%d", &no);
		remain--;
	} while (no != ans && remain > 0);

	if (no != ans)
		printf("����:%d \n", ans);
	else
	{
		printf("�ش���ȷ");
		printf("ʹ����%d�β�����", MAX_stage - remain);
	}
	system("pause");
	return 0;
}
>>>>>>> 634ba00e030601e4cec9467f3e449aa7e4dc8391
