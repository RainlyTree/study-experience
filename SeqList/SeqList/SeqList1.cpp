#define _CRT_SECURE_NO_WARNINGS
#include"SeqList1.h"
#include"assert.h"
#include<string.h>
#include<iostream>



//typedef struct SeqList
//{
//	DataType *array;
//	size_t size;
//	size_t capacity;
//}SeqList;


//��ʼ��˳���
void SeqListInit(SeqList* ps, size_t capacity)
{
	if (ps == NULL)
	{
		std::cout << "��δ��ʼ���ṹ��" << std::endl;
		return;
	}
	ps->array = new DataType[capacity];
	ps->capacity = capacity;
	ps->size = 0;
}
//����˳���
void SeqListDestory(SeqList *ps)
{
	testInit(ps);
	delete ps->array;
	ps->size = 0;
}
//�������
void CheckCapacity(SeqList* ps)
{
	testInit(ps);
	if (ps->capacity == ps->size)
	{
		ps->capacity *= 2;
		ps->array = (int*)realloc(ps->array, ps->capacity * 2 * sizeof(int));
	}
}
//β��
void SeqListPushBack(SeqList* ps, DataType x)
{
	testInit(ps);
	//�������
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	++ps->size;
}
//βɾ
void SeqListPopBack(SeqList *ps)
{
	testInit(ps);
	if (ps->size > 0)
	{
		--ps->size;
	}
}
//ͷ��
void SeqListPushFront(SeqList *ps, DataType x)
{
	testInit(ps);
	CheckCapacity(ps);
	for (int i = ps->size; i > 0; --i)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = x;
	++ps->size;
}
//ͷɾ
void SeqListPopFront(SeqList *ps)
{
	assert(ps->array);
	--ps->size;
	for (int i = 0; i < ps->size; ++i)
	{
		ps->array[i] = ps->array[i + 1];
	}
}
//Ѱ��λ��
int SeqListFind(SeqList* ps, DataType x)
{
	assert(ps->array);
	for (int i = 0; i < ps->size; ++i)
	{
		if (x == ps->array[i])
			return i;
	}
	return -1;
}
//����Ԫ��
void SeqListInsert(SeqList* ps, size_t pos, DataType x)
{
	//���ڵ�ǰλ��
	assert(ps->array);
	CheckCapacity(ps);
	if (pos > ps->size)
	{
		std::cout << "λ��̫���� �Դ�������һ��λ��" << std::endl;
		pos = ps->size;
	}
	if (pos < 0)
	{
		std::cout << "λ��û�и�ֵ�� ���ڳ�ʼλ��" << std::endl;
		pos = 0;
	}
	for (int i = ps->size; i > pos; --i)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[pos] = x;
	++ps->size;
}
//ɾ��Ԫ��
void SeqListErase(SeqList *ps, size_t pos)
{
	assert(ps->array);
	for (int i = pos; i < ps->size; ++i)
	{
		ps->array[i] = ps->array[i + 1];
	}
	--ps->size;
}
//�޸ĵ�ǰλ�õ�ֵ
void SeqListModify(SeqList* ps, size_t pos, DataType x)
{
	assert(ps->array);
	if (pos - 1 > ps->size || pos < 0)
	{
		std::cout << "λ�ù��ڿ��� �� ���ڿ�ǰ " << std::endl;
	}
	ps->array[pos] = x;
}
//��ӡ
void SeqListPrint(SeqList* ps)
{
	assert(ps->array);
	for (int i = 0; i < ps->size; ++i)
	{
		std::cout << ps->array[i] << std::endl;
	}
}
//����DataType array�Ƿ�δ��ʼ��
void testInit(SeqList* ps)
{
	if (ps->array == NULL)
	{
		std::cout << "δ��ʼ������  �Զ��������� capacity = 2" << std::endl;
		SeqListInit(ps, 2);
	}
	
}

