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
	sort,
	Destory,
	change
};




#define MAX_NAME 20
#define MAX_TEL 11
#define MAX_ADD 15
#define MAX_SEX 2

#define MAX_NUMPERSON 1000
#define DEFAULT_SIZE 2
//个人信息
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
	PersonInfo *per;
	int usedSize;//被使用的个数
	int capticty;//容量
}Contact;

void InitContact(Contact *pCon);

void AddContact(Contact *pCon);

int SearchContact(Contact *pCon);	//找到返回下标 找不到返回-1

void DelContact(Contact *pCon);

void ShowContact(Contact *pCon);

void ClearContact(Contact *pCon);

void DestroyContact(Contact *pCon);

void SortContact(Contact *pCon);

void Contact_WriteInfo(Contact *pCon);

void Contact_ReadInfo(Contact *pCon);

void ChangeContact(Contact *pCon);

#endif