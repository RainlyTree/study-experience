#pragma once
#define _CONTACT_H_
#ifdef _CONTACT_H_
#include<assert.h>
enum Option
{
	EXIT,
	add,
	search,
	del,
	show,
	clear,
	sort
};




#define MAX_NAME 20
#define MAX_TEL 11
#define MAX_ADD 15
#define MAX_SEX 2

#define MAX_NUMPERSON 1000
//������Ϣ
typedef struct PersonInfo
{
	char name[MAX_NAME];
	short age;
	char tele[MAX_TEL];
	char addr[MAX_ADD];
	char sex[MAX_SEX];
}PersonInfo;

typedef struct Contact
{
	PersonInfo per[MAX_NUMPERSON];
	int usedSize;//��ʹ�õĸ���
}Contact;

void InitContact(Contact *pCon);

void AddContact(Contact *pCon);

int SearchContact(Contact *pCon);	//�ҵ������±� �Ҳ�������-1

void DelContact(Contact *pCon);

void ShowContact(Contact *pCon);

void ClearContact(Contact *pCon);
#endif