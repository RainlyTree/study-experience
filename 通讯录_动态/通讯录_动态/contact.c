#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"contact.h"

void InitContact(Contact *pCon)
{
	assert(pCon != NULL);

	pCon->capticty = DEFAULT_SIZE;
	pCon->usedSize = 0;
	pCon->per = (PersonInfo *)malloc(sizeof(PersonInfo) * pCon->capticty);
	assert(pCon->per != NULL);
	memset(pCon->per, 0, sizeof(pCon->per));

	Contact_ReadInfo(pCon);
}

static int CheckFull(Contact *pCon)	//�ж��Ƿ���
{
	if (pCon->usedSize == pCon->capticty)
	{
		PersonInfo *p = NULL;
		p = (PersonInfo *)realloc(pCon->per, sizeof(PersonInfo) * pCon->capticty * 2);
		if (p != NULL)
		{
			pCon->per = p;
			pCon->capticty = 2 * pCon->capticty;
			printf("���ݳɹ�\n");
			return 1;
		}
		else
			return 0;
	}
	return 1;
}

void SortContact(Contact *pCon)
{
	assert(pCon != NULL);
	PersonInfo tmp;
	for (int i = 0; i < pCon->usedSize - 1; i++)
	{
		for (int j = 0; j < pCon->usedSize - 1- i; j++)
		{
			if (strcmp(pCon->per[j].name, pCon->per[j + 1].name))
			{
				tmp = pCon->per[j];
				pCon->per[j] = pCon->per[j + 1];
				pCon->per[j + 1] = tmp;
			}
		}
	}
}

void AddContact(Contact *pCon)
{
	//1 ������� ���� �±�
	//2 �Ա� ���䡣������
	assert(pCon != NULL);

	int ret = CheckFull(pCon);
	if (ret != 1)
	{
		printf("����ʧ��\n");
		return;
	}
	int n = pCon->usedSize;
	printf("name :");
	scanf("%s", pCon->per[n].name);
	printf("age  :");
	scanf("%d", &(pCon->per[n].age));
	printf("tele :");
	scanf("%s", pCon->per[n].tele);
	printf("addr :");
	scanf("%s", pCon->per[n].addr);
	printf("sex  :");
	scanf("%s", pCon->per[n].sex);
	pCon->usedSize++;
	printf("��ӳɹ�\n");
}

void ChangeContact(Contact *pCon)
{
	assert(pCon != NULL);

	int n;
	printf("input the number:");
	scanf("%d", &n);
	n = n - 1;
	printf("name :");
	scanf("%s", pCon->per[n].name);
	printf("age  :");
	scanf("%d", &(pCon->per[n].age));
	printf("tele :");
	scanf("%s", pCon->per[n].tele);
	printf("addr :");
	scanf("%s", pCon->per[n].addr);
	printf("sex  :");
	scanf("%s", pCon->per[n].sex);
	printf("�޸ĳɹ�\n");
}

int SearchContact(Contact *pCon)
{
	assert(pCon != NULL);
	char InName[MAX_NAME];
	if (pCon->usedSize == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return -1;
	}
	printf("input the name:");
	scanf("%s", InName);
	for (int i = 0; pCon->usedSize < MAX_NUMPERSON; i++)
	{
		if (strcmp(pCon->per[i].name, InName))
			return i;
	}
	return -1;
}


void DelContact(Contact *pCon)
{
	assert(pCon != NULL);
	int i = SearchContact(pCon);
	if (i == -1)
	{
		printf("���޴���\n");
		return;
	}
	for (; i < pCon->usedSize - 1; i++)
	{
		pCon->per[i] = pCon->per[i + 1];
	}
	pCon->usedSize--;
	printf("ɾ���ɹ�\n");
}

void ShowContact(Contact *pCon)
{
	assert(pCon != NULL);
	printf("%-20s %-3s %-3s %-11s %-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (int i = 0; i < pCon->usedSize; i++)
	{
		printf("%-20s %-3s %-3d %-11s %-15s\n", pCon->per[i].name, pCon->per[i].sex, pCon->per[i].age, pCon->per[i].tele, pCon->per[i].addr);
	}
}

void ClearContact(Contact *pCon)		//�������
{
	memset(pCon->per,0,sizeof(pCon->per));
}


void DestroyContact(Contact *pCon)		//���ڴ�
{
	Contact_WriteInfo(pCon);
	assert(pCon != NULL);
	free(pCon->per);
	pCon->per = NULL;
	pCon->capticty = 0;
	pCon->usedSize = 0;
}

static void ADD(Contact *pCon, PersonInfo *tmp)
{
	CheckFull(pCon);
	pCon->per[pCon->usedSize] = *tmp;
	pCon->usedSize++;
}

void Contact_ReadInfo(Contact *pCon)			//���ļ������ݵ���ϵͳ
{
	FILE *fp;
	if ((fp = fopen("Database.txt", "rb")) == NULL)
	{
		printf("���ܴ��ļ�!\n");
		return;
	}
	PersonInfo tmp;
	while (fread(&tmp, sizeof(PersonInfo), 1, fp))
	{
		ADD(pCon,&tmp);
	}
	fclose(fp);
	fp = NULL;
}

void Contact_WriteInfo(Contact *pCon)				//��ϵͳ����д���ļ�
{
	FILE *fp;
	if ((fp = fopen("Database.txt", "wb")) == NULL)
	{
		printf("���ܴ��ļ�!\n");
		return;
	}
	for (int i = 0; i < pCon->usedSize; i++)
	{
		fwrite(pCon->per + i, sizeof(PersonInfo), 1, fp);
	}
	fclose(fp);
	fp = NULL;
}
