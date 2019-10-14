#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"BinaryTree.h"
#include"Queue.h"
#include"Stack.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else
		return NULL;
}

void BinaryTreeDestory(BTNode** root)
{

	if (*root)
	{
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
		*root = NULL;
	}
}

int BinaryTreeSize(BTNode* root)
{
	if (root)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

//��k��ڵ�ĸ���
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) +
		BinaryTreeLevelKSize(root->_right, k - 1);
}

//�ҵ�ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root == NULL)
		return NULL;	
	if (root->_data == x)
		return root;
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;
	return NULL;
}

// ����
//�ݹ�

void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
}


// �ǵݹ����

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	//���ڵ����
	if (root)
		QueuePush(&q, root);
	//ÿ�γ���ͷԪ�أ��������ӽڵ㣬���
	while (QueueEmpty(&q) == 0)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//����
		printf("%c ", front->_data);
		//�������
		if (front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
	printf("\n");
}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (QueueEmpty(&q) == 0)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
			break;
	}
	while (QueueEmpty(&q) == 0)
	{
		BTNode* front = QueueFront(&q);
		//�ж��Ƿ�Ϊ��,����ǿգ�˵��������
		if (front)
		{
			QueueDestroy(&q);
			return 0;
		}
		QueuePop(&q);
	}
	return 1;
}

//�ǵݹ�ǰ�����
void BinaryTreePrevOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* top;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&st, cur);
			cur = cur->_left;
		}
		//�������һ��������������
		top = StackTop(&st);
		StackPop(&st);
		cur = top->_right;
	}
	printf("\n");
}

void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* top;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) == 0)
	{
		//����߶�ѹ��ջ
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		top = StackTop(&st);
		printf("%c ", top->_data);
		StackPop(&st);
		cur = top->_right;
	}
	printf("\n");
}

//�ǵݹ�������
void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* top;
	BTNode* prev = NULL;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		top = StackTop(&st);
		
		//�ж��Ƿ���������
		if(top->_right == NULL || top->_right == prev)
		{
			printf("%c ", top->_data);
			StackPop(&st);
			prev = top;
		}
		//����������������������Ѿ��������ˣ����Է��ʸ�
		else
		{
			cur = top->_right;
		}
	}
	printf("\n");
}

void TestBinaryTree()
{
	int i = 0;
	char a[] = { 'A','B','D','G','#','#','H','#','#',
		'#','C','E','#','I','#','#','F','#','#' };
	BTNode* root = BinaryTreeCreate(a, &i);
	BinaryTreePrevOrderNonR(root);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreePostOrderNonR(root);
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeInOrderNonR(root);
	BinaryTreeInOrder(root);
}

int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}