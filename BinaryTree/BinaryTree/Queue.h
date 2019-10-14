#pragma once
#include "BinaryTree.h"
typedef BTNode* LDataType;
typedef struct QueueNode
{
	LDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);

//��β����Ԫ��
void QueuePush(Queue* q, LDataType x);
//��ͷɾ��Ԫ��
void QueuePop(Queue* q);

//��ȡ��ͷԪ��
LDataType QueueFront(Queue* q);
//��ȡ��βԪ��
LDataType QueueBack(Queue* q);

int QueueEmpty(Queue* q);
int QueueSize(Queue* q);

void QueuePrint(Queue* q);