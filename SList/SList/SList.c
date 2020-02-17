#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include"SList.h"

//typedef struct SListNode
//{
//	SLTDataType _data;
//	struct SListNode* _next;
//}SListNode;
//
//typedef struct SList
//{
//	SListNode* _head;
//}SList;



//����
void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = (SListNode*)malloc(sizeof(SListNode));
	plist->_head->_next	= NULL;
	plist->_head->_data = -1;
}

//����
void SListDestory(SList* plist)
{
	assert(plist->_head);
	while (plist->_head != NULL)
	{
		SListNode* tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
	plist->_head = NULL;
	plist = NULL;
}

//����һ���ڵ�
SListNode* BuySListNode(SLTDataType x)
{
	SListNode *New = (SListNode*)malloc(sizeof(SListNode));
	if (New == NULL)
		return New;
	New->_data = x;
	New->_next = NULL;
	return New;
}

//ͷ��
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist->_head);
	SListNode* new = BuySListNode(x);
	if (plist->_head->_next == NULL)
	{
		plist->_head->_next = new;
	}
	else
	{
		new->_next = plist->_head->_next;
		plist->_head->_next = new;
	}
}

//ͷɾ
void SListPopFront(SList* plist)
{
	assert(plist->_head);
	if (plist->_head->_next == NULL)
		;
	else
	{
		SListNode* new = plist->_head->_next;
		plist->_head->_next = plist->_head->_next->_next;
		free(new);
	}
}

//����һ����
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	if (x < 1)
		return NULL;
	SListNode* new = plist->_head;
	while (x > 0 && new != NULL)
	{
		new = new->_next;
		--x;
	}
	if (x == 0)
		return new;
	return NULL;
}

// ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* new = BuySListNode(x);
	SListNode* next = pos->_next;
	new->_next = next;
	pos->_next = new;
}

//βɾ
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->_next == NULL)
		return;
	SListNode* front, *next;
	front = pos;
	next = pos->_next;
	while (next->_next)
	{
		front = front->_next;
		next = next->_next;
	}
	front->_next = NULL;
	free(next);
}

//ɾ������ڵ�
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	if (plist->_head->_next == NULL)
		return;
	SListNode* front = plist->_head;
	while (front->_next != NULL)
	{
		SListNode *fee = front->_next;
		if (fee->_data == x)
		{
			if (fee->_next == NULL)
			{
				front->_next = NULL;
				free(fee);
			}
			else
			{
				fee->_data = fee->_next->_data;
				fee->_next = fee->_next->_next;
				free(fee->_next);
			}
		}
		else
		{
			front = front->_next;
		}
	}
}

void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* new = plist->_head->_next;
	while (new)
	{
		printf("%d ", new->_data);
		new = new->_next;
	}
	printf("\n");
}
void TestSList()
 {
	SList text;
	SListInit(&text);
	SListPushFront(&text, 1);
	SListPushFront(&text, 2);
	SListPushFront(&text, 3);
	SListPushFront(&text, 4);
	SListInsertAfter((&text)->_head, 0);
	SListPrint(&text);
	//SListPopFront(&text);
	//SListPopFront(&text);
	//SListPopFront(&text);
	//SListPopFront(&text);
	//SListPopFront(&text);
	SListInsertAfter((&text)->_head, 0);
	SListPrint(&text);
	SListDestory(&text);
	//SListRemove(&text, 2);
	//SListRemove(&text, 1);
	//SListPrint(&text);

	//SListNode* new = SListFind(&text, 2);
	//printf("%d\n", new->_data);
	//SListEraseAfter((&text)->_head);
}

int main()
{
	TestSList();
	system("pause");
	return 0;
}