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

//队尾插入元素
void QueuePush(Queue* q, LDataType x);
//队头删除元素
void QueuePop(Queue* q);

//获取队头元素
LDataType QueueFront(Queue* q);
//获取队尾元素
LDataType QueueBack(Queue* q);

int QueueEmpty(Queue* q);
int QueueSize(Queue* q);

void QueuePrint(Queue* q);