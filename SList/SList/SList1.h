#pragma once

// 一个无头结点的单向非循环链表实现
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

//建立
void SListInit(SList* plist);

//销毁
void SListDestory(SList* plist);

//新增一个节点
SListNode* BuySListNode(SLTDataType x);

//头插
void SListPushFront(SList* plist, SLTDataType x);

//头删
void SListPopFront(SList* plist);

//查找一个数
SListNode* SListFind(SList* plist, SLTDataType x);

// 在 x 后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x);

//尾删
void SListEraseAfter(SListNode* pos);

//删除任意节点
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void TestSList();