#pragma once
// 2����ͷ˫��ѭ��������ɾ���ʵ�� 
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

//��ʼ��
void ListInit(List* plist);

//����
void ListDestory(List* plist);

<<<<<<< HEAD
void ListPushBack(List* plist, LTDataType x);
void ListPushFront(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPopFront(List* plist);

=======
>>>>>>> 1ffd60aeb7e12a65cb7a2920ac0d50d052f124e7
// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x); 

// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos); 

//ɾ��ֵΪx�Ľڵ�
void ListRemove(List* plist, LTDataType x);

void ListPrint(List* plist);
