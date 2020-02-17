#pragma once

// һ����ͷ���ĵ����ѭ������ʵ��
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _first;
}SList;

//����
void SListInit(SList* plist);

//����
void SListDestory(SList* plist);

//����һ���ڵ�
SListNode* BuySListNode(SLTDataType x);

//ͷ��
void SListPushFront(SList* plist, SLTDataType x);

//ͷɾ
void SListPopFront(SList* plist);

//����һ����
SListNode* SListFind(SList* plist, SLTDataType x);

// �� x ������в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x);

//βɾ
void SListEraseAfter(SListNode* pos);

//ɾ������ڵ�
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void TestSList();