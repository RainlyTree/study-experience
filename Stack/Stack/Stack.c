#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include"Stack.h"

//typedef struct Stack
//{
//	DataType* _a;
//	size_t _top;
//	size_t _capacity;
//}Stack;

void StackInit(Stack* st)
{
	st->_a = NULL;
	st->_capacity = st->_top = 0;
}

void StackDestory(Stack* st)
{
	free(st->_a);
	st->_top = st->_capacity = 0;
}

void StackPush(Stack* st, DataType x)
{
	//ÈëÕ»£ºË³Ðò±íÎ²²å
	//¼ì²éÈÝÁ¿
	assert(st);
	if (st->_top == st->_capacity)
	{
		size_t newC = st->_capacity == 0 ? 10 : 2 * st->_capacity;
		st->_a = (DataType*)realloc(st->_a, newC * sizeof(DataType));
		st->_capacity = newC;
	}
	//²åÈë
	st->_a[st->_top++] = x;
}

void StackPop(Stack* st)
{
	//³öÕ»£ºÎ²É¾
	assert(st);
	if(st->_top)
		--st->_top;
}

//²é¿´Õ»¶¥ÔªËØ
DataType StackTop(Stack* st)
{
	assert(st);
	return st->_a[st->_top - 1];
}

size_t StackSize(Stack* st)
{
	return st->_top;
}

int StackEmpty(Stack* st)
{
	assert(st);
	return st->_top == 0 ? 1 : 0;
}

void StackPrint(Stack* st)
{
	assert(st);
	while (StackEmpty(st) != 1)
	{
		printf("%d ", StackTop(st));
		StackPop(st);
	}
	printf("\n");
}

void textStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPrint(&s);
	StackDestory(&s);
}

int main()
{
	textStack();
	system("pause");
	return 0;
}