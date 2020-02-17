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


//初始化顺序表
void SeqListInit(SeqList* ps, size_t capacity)
{
	if (ps == NULL)
	{
		std::cout << "还未初始化结构体" << std::endl;
		return;
	}
	ps->array = new DataType[capacity];
	ps->capacity = capacity;
	ps->size = 0;
}
//销毁顺序表
void SeqListDestory(SeqList *ps)
{
	testInit(ps);
	delete ps->array;
	ps->size = 0;
}
//检查容量
void CheckCapacity(SeqList* ps)
{
	testInit(ps);
	if (ps->capacity == ps->size)
	{
		ps->capacity *= 2;
		ps->array = (int*)realloc(ps->array, ps->capacity * 2 * sizeof(int));
	}
}
//尾插
void SeqListPushBack(SeqList* ps, DataType x)
{
	testInit(ps);
	//检查容量
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	++ps->size;
}
//尾删
void SeqListPopBack(SeqList *ps)
{
	testInit(ps);
	if (ps->size > 0)
	{
		--ps->size;
	}
}
//头插
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
//头删
void SeqListPopFront(SeqList *ps)
{
	assert(ps->array);
	--ps->size;
	for (int i = 0; i < ps->size; ++i)
	{
		ps->array[i] = ps->array[i + 1];
	}
}
//寻找位置
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
//插入元素
void SeqListInsert(SeqList* ps, size_t pos, DataType x)
{
	//插在当前位置
	assert(ps->array);
	CheckCapacity(ps);
	if (pos > ps->size)
	{
		std::cout << "位置太靠后 以存放在最后一个位置" << std::endl;
		pos = ps->size;
	}
	if (pos < 0)
	{
		std::cout << "位置没有负值， 放在初始位置" << std::endl;
		pos = 0;
	}
	for (int i = ps->size; i > pos; --i)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[pos] = x;
	++ps->size;
}
//删除元素
void SeqListErase(SeqList *ps, size_t pos)
{
	assert(ps->array);
	for (int i = pos; i < ps->size; ++i)
	{
		ps->array[i] = ps->array[i + 1];
	}
	--ps->size;
}
//修改当前位置的值
void SeqListModify(SeqList* ps, size_t pos, DataType x)
{
	assert(ps->array);
	if (pos - 1 > ps->size || pos < 0)
	{
		std::cout << "位置过于靠后 或 过于靠前 " << std::endl;
	}
	ps->array[pos] = x;
}
//打印
void SeqListPrint(SeqList* ps)
{
	assert(ps->array);
	for (int i = 0; i < ps->size; ++i)
	{
		std::cout << ps->array[i] << std::endl;
	}
}
//测试DataType array是否还未初始化
void testInit(SeqList* ps)
{
	if (ps->array == NULL)
	{
		std::cout << "未初始化数组  自动生成数组 capacity = 2" << std::endl;
		SeqListInit(ps, 2);
	}
	
}

