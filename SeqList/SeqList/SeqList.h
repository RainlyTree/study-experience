#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;

typedef struct SeqList
{
	DataType *arr;
	size_t size;
	size_t capacity;
}SeqList;

//初始化顺序表
void SeqListInit(SeqList* ps, size_t capacity);
//销毁顺序表
void SeqListDestory(SeqList *ps);
//检查容量
void CheckCapacity(SeqList* ps);
//头删
void SeqListPushBack(SeqList* ps, DataType x);
//尾删
void SeqListPopBack(SeqList *ps);
//头插
void SeqListPushFront(SeqList *ps, DataType x);
//尾插
void SeqListPopFront(SeqList *ps);
//寻找位置
int SeqListFind(SeqList* ps, DataType x);
//插入元素
void SeqListInsert(SeqList* ps, size_t pos, DataType x);
//删除元素
void SeqListErase(SeqList *ps, size_t pos);
//向前移动
void SeqListMove(SeqList* ps, DataType x);
//修改当前位置的值
void SeqListModify(SeqList* ps, size_t pos, DataType x);
//打印
void SeqListPrint(SeqList* ps);