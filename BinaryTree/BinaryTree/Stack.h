#pragma once
#include"BinaryTree.h"
//顺序表实现栈
typedef BTNode* DataType;
typedef struct Stack
{
	DataType* _a;
	size_t _top;
	size_t _capacity;
}Stack;

void StackInit(Stack* st);
void StackDestory(Stack* st);
void StackPush(Stack* st, DataType x);
void StackPop(Stack* st);

//查看栈顶元素
DataType StackTop(Stack* st);
size_t StackSize(Stack* st);
int StackEmpty(Stack* st);

void StackPrint(Stack* st);