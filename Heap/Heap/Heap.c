#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include"Heap.h"

void Swap(HPDataType* pa, HPDataType* pb)
{
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	int i;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)* n);
	for (i = 0; i < n; ++i)
	{
		hp->_a[i] = a[i];
	}
	//���е���,�����һ���������е���
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(hp->_a, n, i);
	}
	//ԭ����֤�����������Ƕѣ�Ȼ��������µ���
	hp->_size = hp->_capacity = n;
}

void HeapEmptyInit(Heap* hp)
{
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}


void ShiftDown(HPDataType* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	//��ǰ�Ľڵ��Ƿ��к���
	while (child < n)
	{
		//�Ƿ����Һ���, ����У�������ѡ����
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		//�����Ƿ���ڸ���
		if (a[child] > a[parent])
		{
			//�������Ӻ͸���
			Swap(&a[child], &a[parent]);
			//������һ�ε�����λ��
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//��parentΪ���������Ѿ���һ����ѣ���������
			break;
		}
	}
}

//���ϵ���   ��β��һ��Ԫ�أ��뵱ǰ�����ĸ��ڵ���бȽϣ�����γɴ�ѣ�
void ShiftUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (parent >= 0)			//	while(child > 0)������
	{
		if (a[parent] > a[child])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapDestory(Heap* hp)
{
	if (hp->_a)
	{
		free(hp->_a);
		hp->_a = NULL;
		hp->_size = hp->_capacity = 0;
	}
}

//����
void HeapPush(Heap* hp, HPDataType x)
{
	//�������
	if (hp->_size == hp->_capacity)
	{
		int newC = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, newC * sizeof(HPDataType));
		hp->_capacity = newC;
	}
	//���� ���ϵ���
	hp->_a[hp->_size] = x;
	++hp->_size;
	ShiftUp(hp->_a, hp->_size, hp->_size - 1);
}

//ɾ���Ѷ�Ԫ��,ɾ����ֵ ���/��С
void HeapPop(Heap* hp)
{
	//��Ϊ��Ϊ0
	if (HeapEmpty(hp) == 0)
	{
		Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
		//βɾ
		--hp->_size;
		ShiftDown(hp->_a, hp->_size, 0);
	}
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp->_size);
	return hp->_a[0];
}

int HeapSize(Heap* hp)
{
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}

// ������
void HeapSort(int* a, int n)
{
	//����
	int i;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(a, n, i);
	}

	//������

	int end = n - 1;
	while (end > 0)
	{
		//����
		Swap(&a[0], &a[end]);
		//�ӶѶ����µ���
		ShiftDown(a, end, 0);
		--end;
	}
}

void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void TestHeap()
{
	int a[] = { 1, 5, 3, 8, 7, 6 };
	//������ѣ�����֮��hp->_a[] = {8, 7, 6, 5, 1, 3};
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);
}

void textHeap1()
{
	Heap hp;
	HeapEmptyInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	HeapPush(&hp, 4);
	HeapPush(&hp, 5);
	HeapPush(&hp, 6);
	HeapPush(&hp, 7);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapSort((&hp)->_a, (&hp)->_size);
	HeapPrint(&hp);
}

int main()
{
	textHeap1();
	system("pause");
	return 0;
}