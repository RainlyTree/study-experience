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
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_data = -1;
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

ListNode* BuildNewNode(LTDataType x)
{
	ListNode* New = (ListNode*)malloc(sizeof(ListNode));
	New->_data = x;
	New->_next = New;
	New->_prev = New;
	return New;
}

//销毁
void ListDestory(List* plist)
{
	assert(plist);
	if (plist->_head == plist->_head->_next)
		return;
	ListNode* fee = plist->_head->_next;
	ListNode* next = fee->_next;
	while (fee != plist->_head)
	{
		free(fee);
		fee = next;
		next = next->_next;
	}
	plist->_head->_next  = plist->_head;
}


// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* new = BuildNewNode(x);
	ListNode* front = pos->_prev;
	new->_next = pos;
	new->_prev = pos->_prev;
	front->_next = new;
	pos->_prev = new;
}

// 删除pos位置的节点
void ListErase(ListNode* pos)
{
	if (pos->_next == pos)
		return;
	ListNode* front = pos->_prev;
	ListNode* next = pos->_next;
	front->_next = next;
	next->_prev = front;
	free(pos);
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
	assert(plist->_head);
	ListNode* eve = plist->_head->_next;
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