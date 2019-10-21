#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


//时间O(n²)
//空间O(1)
//稳定
//适用场景：接近有序的序列
//InsertSort插入排序
void MyInsertSort(int* arr, int n)
{
	assert(arr);
	int i, tmp, end;
	//对每一个元素进行排序
	for (i = 0; i < n - 1; ++i)
	{
		end = i;
		tmp = arr[end + 1];
		while (end >= 0 && arr[end] > tmp)
		{
			//对单个元素进行位置调整
			arr[end + 1] = arr[end];
			--end;
		}
		//将所有大的元素已经放到后面,插入当前元素
		arr[end + 1] = tmp;
	}
}


//时间复杂度O(n^1.3 到 ^2)
//空间复杂度O(1)
//稳定性：不稳定
//shellSort 希尔排序
void ShllSort(int* arr, int n)
{
	//表示间隔
	int gap = n;
	int i;
	while (gap > 1)
	{
		gap = gap / 3 + 1;		//保证不进入死循环
		for (i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0 && arr[end] > tmp)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = tmp;
		}
	}
}

//时间复杂度：O(n²)
//空间复杂度：O(1)
//稳定性：不稳定
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//每次选最大的和最小的，放到相应位置
		int i, max, min;
		max = min = begin;
		for (i = begin; i <= end; i++)
		{
			if (a[i] < min)
				min = i;
			if (a[i] > max)
				max = i;
		}
		Swap(&a[begin], &a[min]);
		if (max = begin)			//注意可能最大值在开头 可能被中途替换
			max = min;
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}

void ShiftDown(int *a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n)
{
	int i;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		ShiftDown(a, end, 0);
		--end;
	}
}

//时间复杂度:O(n² ~ n)
//空间复杂度:O(1)
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void Swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


void printarr(int* arr, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
}
void text()
{
	int a[10] = { 1, 10, 8, 9, 3, 7 ,4 ,13, 4, 2 };
	MyInsertSort(a, 10);
	printarr(a, 10);
}

int main()
{
	text();
	system("pause");
	return 0;
}