#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include"ListNode.h"

//初始化
void ListInit(List* plist)
{
	assert(plist);
	plist->_head = BuildNewNode(0);
	plist->_head = (ListNode*)malloc(sizeof(ListNode));

	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

ListNode* BuildNewNode(LTDataType x)
{
	ListNode* New = (ListNode*)malloc(sizeof(ListNode));
	New->_data = x;

	New->_next = New->_prev = NULL;
	return New;
}

//销毁
void ListDestory(List* plist)
{
	assert(plist);
	if (plist->_head == plist->_head->_next)
		return;
	ListNode* fee = plist->_head->_next;

	while (fee != plist->_head)
	{
		ListNode* next = fee->_next;
		free(fee);
		fee = next;
	}
	free(plist->_head);
}

//头插
void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* tail;
	ListNode* newNode = BuildNewNode(x);
	tail = plist->_head->_prev;
	tail->_next = newNode;
	newNode->_prev = tail;
	newNode->_next = plist->_head;
	plist->_head->_prev = newNode;
}

void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* next;
	ListNode* newNode = BuildNewNode(x);
	next = plist->_head->_next;

	plist->_head->_next = newNode;
	newNode->_next = next;
	next->_prev = newNode;
	newNode->_prev = plist->_head;
}

//尾删
void ListPopBack(List* plist)
{
	assert(plist);
	if (plist->_head == plist->_head->_next)
		return;

	ListNode* del = plist->_head->_prev;
	ListNode* tail = del->_prev;

	plist->_head->_prev = tail;
	tail->_next = plist->_head;
	free(del);
	del = NULL;
}

//头删
void ListPopFront(List* plist)
{
	assert(plist);
	if (plist->_head == plist->_head->_next)
		return;

	ListNode* del = plist->_head->_next;
	ListNode* tail = del->_next;

	plist->_head->_next = tail;
	tail->_prev = plist->_head;
	free(del);
	del = NULL;
}

// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* new = BuildNewNode(x);
	ListNode* front = pos->_prev;
	new->_next = pos;
	new->_prev = front;

	front->_next = new;
	pos->_prev = new;
}

// 删除pos位置的节点
void ListErase(ListNode* pos)
{

	assert(pos);
	if (pos->_next == pos)
		return;

	ListNode* front = pos->_prev;
	ListNode* next = pos->_next;
	front->_next = next;
	next->_prev = front;
	free(pos);

	pos = NULL;
}

//删除值为x的节点
void ListRemove(List* plist, LTDataType x)
{
	assert(plist->_head);
	ListNode* fee = plist->_head->_next;
	while (fee != plist->_head)
	{
		if (fee->_data == x)
		{
			ListNode* next = fee->_next;
			ListNode* front = fee->_prev;
			front->_next = next;
			next->_prev = front;
			free(fee);
			fee = next;
		}
		else
		{
			fee = fee->_next;
		}
	}
}

void ListPrint(List* plist)
{
	assert(plist);
	ListNode* eve = plist->_head->_next;
	//防止plist->_head之后没有元素
	if (plist->_head == plist->_head->_next)
		return NULL;

	while (eve != plist->_head)
	{
		printf("%d ", eve->_data);
		eve = eve->_next;
	}
	printf("\n");
}

void text()
{
	List text;
	ListInit(&text);
	ListInsert((&text)->_head, 1);
	ListInsert((&text)->_head, 1);
	ListInsert((&text)->_head, 1);
	ListInsert((&text)->_head, 2);
	ListInsert((&text)->_head, 3);
	ListInsert((&text)->_head, 4);
	ListPrint(&text);
	
	/*ListErase(((&text)->_head)->_next);
	ListErase(((&text)->_head)->_next);
	ListErase(((&text)->_head)->_next);
	ListErase(((&text)->_head)->_next);
	ListErase(((&text)->_head)->_next);
	ListPrint(&text);
*/
	ListRemove(&text, 1);
	ListPrint(&text);
	ListDestory(&text);
}

int main()
{
	text();
	system("pause");
	return 0;
}