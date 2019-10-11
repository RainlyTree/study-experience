#pragma once
// 2、带头双向循环链表增删查改实现 
typedef int LTDataType; 

typedef struct ListNode 
{    LTDataType _data;    
	struct ListNode* _next;    
	struct ListNode* _prev; 
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;

//初始化
void ListInit(List* plist);

//销毁
void ListDestory(List* plist);

<<<<<<< HEAD
void ListPushBack(List* plist, LTDataType x);
void ListPushFront(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPopFront(List* plist);

=======
>>>>>>> 1ffd60aeb7e12a65cb7a2920ac0d50d052f124e7
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x); 

// 删除pos位置的节点
void ListErase(ListNode* pos); 

//删除值为x的节点
void ListRemove(List* plist, LTDataType x);

void ListPrint(List* plist);
