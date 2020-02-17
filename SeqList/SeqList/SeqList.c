#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SeqList.h"

//��ʼ��˳���
void SeqListInit(SeqList* ps, size_t capacity)
{
	assert(ps);
	ps->arr = (DataType *)malloc(sizeof(size_t) * capacity);
	ps->capacity = capacity;
	ps->size = 0;
}
//����˳���
void SeqListDestory(SeqList *ps)
{
	assert(ps->arr);
	free(ps->arr);
}
//�������
void CheckCapacity(SeqList* ps)
{
	assert(ps->arr);
	if (ps->capacity == ps->size)
	{
		ps->arr = (DataType *)realloc(ps->arr,sizeof(int)* 2 * ps->capacity);
		ps->capacity = 2 * ps->capacity;
	}
}
//β��
void SeqListPushBack(SeqList* ps, DataType x)
{
	assert(ps->arr);
	CheckCapacity(ps);

	ps->arr[ps->size] = x;
	ps->size++;
}
//βɾ
void SeqListPopBack(SeqList *ps)
{
	assert(ps->arr);
	if (ps->size == 0)
		return;
	ps->size--;

}
//ͷ��
void SeqListPushFront(SeqList *ps, DataType x)
{
	assert(ps->arr);
	CheckCapacity(ps);
	if (ps->size == 0)
	{
		ps->arr[ps->size] = x;
		ps->size++;
	}
	else
	{
		int num = ps->size;
		while (num)
		{
			ps->arr[num] = ps->arr[num - 1];
			--num;
		}
		ps->arr[0] = x;
		ps->size++;
	}
}
//ͷɾ
void SeqListPopFront(SeqList *ps)
{
	assert(ps->arr);
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//Ѱ��λ��
int SeqListFind(SeqList* ps, DataType x)
{
	assert(ps->arr);
	for (size_t i = 0; i < ps->size; i++)
	{
		if (x == ps->arr[i])
			return i;
	}
	return -1;
}

//����Ԫ��
void SeqListInsert(SeqList* ps, size_t pos, DataType x)
{
	assert(ps->arr);
	CheckCapacity(ps);
	if (pos <= ps->size)
	{
		size_t num = ps->size;
		while (pos < num)
		{
			ps->arr[num] = ps->arr[num - 1];
			num--;
		}
		ps->arr[num] = x;
		ps->size++;
	}
}

//ɾ��Ԫ��
void SeqListErase(SeqList *ps, size_t pos)
{
	assert(ps->arr);
	if (pos < ps->size)
	{
		SeqListMove(ps, pos);
	}
}

//��ǰ�ƶ�
void SeqListMove(SeqList* ps, DataType x)
{
	assert(ps->arr);
	while (x < (ps->size - 1))
	{
		ps->arr[x] = ps->arr[x + 1];
		x++;
	}
	ps->size--;
}
//�޸ĵ�ǰλ�õ�ֵ
void SeqListModify(SeqList* ps, size_t pos, DataType x)
{
	assert(ps->arr);
	if (pos < ps->size)
	{
		ps->arr[pos] = x;
	}
}
//��ӡ
void SeqListPrint(SeqList* ps)
{
	assert(ps->arr);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
}

void text()
{
	SeqList text;
	SeqListInit(&text, 5);
	SeqListInsert(&text, 0, 0);
	SeqListPrint(&text);
	printf("\n");
	SeqListInsert(&text, 1, 1);
	SeqListPrint(&text);
	printf("\n");
	SeqListInsert(&text, 2, 2);
	SeqListPrint(&text);
	printf("\n");
	SeqListPopBack(&text);
	SeqListPrint(&text);
	printf("\n");
	SeqListPopFront(&text);
	SeqListPrint(&text);
	printf("\n");
	SeqListPushBack(&text, 10);
	SeqListPrint(&text);
	printf("\n");
	SeqListPushFront(&text, 100);
	SeqListPrint(&text);
	printf("\n");
	int text1 = SeqListFind(&text, 10);
	printf("%d\n", text1);
	SeqListErase(&text, 0);
	SeqListPrint(&text);
	printf("\n");
	SeqListErase(&text, 0);
	SeqListPrint(&text);
	printf("\n");
	SeqListErase(&text, 0);
	SeqListPrint(&text);
}
//
//int main()
//{
//	text();
//	system("pause");
//	return 0;
//}