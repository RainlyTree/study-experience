#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include"Queue.h"


void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

//��β����Ԫ��
void QueuePush(Queue* q, LDataType x)
{
	assert(q);

	QueueNode* newC = (QueueNode*)malloc(sizeof(QueueNode));
	newC->_data = x;
	newC->_next = NULL;

	//�ж��Ƿ�Ϊ��һ�������Ԫ��
	if (q->_front == NULL)
	{
		q->_front = q->_rear = newC;
	}
	else
	{
		q->_rear->_next = newC;
		q->_rear = q->_rear->_next;
	}
}

//��ͷɾ��Ԫ��
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front)
	{
		QueueNode* next = q->_front->_next;
		//ɾ������
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL)
			q->_rear = NULL;
	}
}

//��ȡ��ͷԪ��
LDataType QueueFront(Queue* q)
{
	assert(q);
	if(q->_front)
		return q->_front->_data;
	return NULL;
}
//��ȡ��βԪ��
LDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}
int QueueSize(Queue* q)
{
	assert(q);
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		++n;
		cur = cur->_next;
	}
	return n;
}

void QueuePrint(Queue* q)
{
	assert(q);
	while (QueueEmpty(q) == 0)
	{
		printf("%c ", QueueFront(q)->_data);
		QueuePop(q);
	}
	printf("\n");
}
