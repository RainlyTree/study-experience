<<<<<<< HEAD
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//int main()
//{
//	int ans = 0;    //Ŀ������
//	int no = 0;     //��ȡ����
//	const int MAX_stage = 10;    //����������Ĵ���
//	int remain = MAX_stage;
//
//	srand((unsigned int)time(NULL));               //�������������
//	ans = rand() % 1000;         //����0-999֮�����
//
//	printf("��  0 ~ 999 ֮�������\n");
//	do
//	{
//		printf("��ʣ��%d�λ��᣺", remain);
//		// %d ��ȡ���� ������ֱ������ �������ֽ���
//		scanf("%d", &no);                         //���û��getchar()����Ϊ������ĸ��ѭ��
//		//getchar();                                //��ֹ��Ϊ������ĸ��ѭ��
//		while ('\n' != getchar());                //��֤�����ĸ���룬����ĸȫ���޳�
//		remain--;								  //һ��getcharֻ���ֹһ����ĸ�������ĸ����ѭ����
//		if (no > ans)
//			printf("\a��Сһ��\n");
//		else if (no < ans)
//			printf("\a�ٴ�һ��\n");
//	} while (no != ans && remain > 0);
//
//	if (no != ans)
//		printf("����:%d", ans);
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
	int ans = 0;    //Ŀ������
	int no = 0;     //��ȡ����
	const int MAX_stage = 10;    //����������Ĵ���
	int remain = MAX_stage;

	srand((unsigned int)time(NULL));               //�������������
	ans = rand() % 1000;         //����0-999֮�����

	printf("��  0 ~ 999 ֮�������\n");
	do
	{
		printf("��ʣ��%d�λ��᣺", remain);
		scanf("%d", &no);
		remain--;
		if (no > ans)
			printf("\a��Сһ��\n");
		else if (no < ans)
			printf("\a�ٴ�һ��\n");
	} while (no != ans && remain > 0);

	if (no != ans)
		printf("����:%d", ans);
	else
	{
		printf("�ش���ȷ");
		printf("ʹ����%d�β�����", MAX_stage - remain);
	}
	
	return 0;
}
>>>>>>> 634ba00e030601e4cec9467f3e449aa7e4dc8391