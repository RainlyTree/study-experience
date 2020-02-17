#pragma once
#include<stdio.h>
typedef int DataType;

typedef struct SeqList
{
	DataType* array;
	size_t size;
	size_t capacity;
}SeqList;

//��ʼ��˳���
void SeqListInit(SeqList* ps, size_t capacity);
//����˳���
void SeqListDestory(SeqList *ps);
//�������
void CheckCapacity(SeqList* ps);
//β��
void SeqListPushBack(SeqList* ps, DataType x);
//βɾ
void SeqListPopBack(SeqList *ps);
//ͷ��
void SeqListPushFront(SeqList *ps, DataType x);
//ͷɾ
void SeqListPopFront(SeqList *ps);
//Ѱ��λ��
int SeqListFind(SeqList* ps, DataType x);
//����Ԫ��
void SeqListInsert(SeqList* ps, size_t pos, DataType x);
//ɾ��Ԫ��
void SeqListErase(SeqList *ps, size_t pos);
//�޸ĵ�ǰλ�õ�ֵ
void SeqListModify(SeqList* ps, size_t pos, DataType x);
//��ӡ
void SeqListPrint(SeqList* ps);