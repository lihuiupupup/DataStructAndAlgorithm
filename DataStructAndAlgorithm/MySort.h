#pragma once
#ifndef MYSORT_H_
#define MYSORT_H_
#include <iostream>
#include "MyHeap.h"
int compareTo2(int num1, int num2);

using namespace std;
class MySort
{
public:
	MySort();
	~MySort();
	/*
	相当于抓牌 手上已近抓了一张arr[0],然后没抓取一张就和已经排序好的前半部分比较
	我这里是升序排序 所以从后往前进行 比当前抓取的牌大的就后移 直到找到合适的位置
	跳出循环 放下抓取的牌 重复进行 直到所有的牌抓完
	*/
	void insertSort(int * & arr, int n)
	{
		for (int i = 1; i < n; i++)
		{
			int cur = arr[i];
			int j = i - 1;
			for (; j >= 0; j--)
			{
				if (arr[j] > cur)
				{
					arr[j + 1] = arr[j];
				}
				else
				{
					break;
				}
			}
			arr[j + 1] = cur;
		}

		printArr(arr, n);
	}

	/*
	shell排序 定义一个增量序列【1,....k】 通过递减增量序列 得到每次每隔多少间隔进行交换 消除逆序对
	可以是插入也可以是冒泡 不稳定
	*/
	void shellSort(int * & arr, int n)
	{
		for (int gap = n / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < n; i += gap)
			{
				int cur = arr[i];
				int j = i;
				for (; j >= gap && arr[j - gap] > cur; j -= gap)
				{
					arr[j] = arr[j - gap];
				}

				arr[j] = cur;
			}
		}

		printArr(arr, n);
	}

	/*
	冒泡排序
	*/
	void bubbleSort(int * & arr, int n)
	{
		for (int i = 0; i < n; i++)
		{
			bool isSwap = false;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
					isSwap = true;
				}
			}

			if (!isSwap)
			{
				break;
			}
		}

		printArr(arr, n);
	}

	/*
	选择排序 不稳定
	*/
	void selectSort(int * & arr, int n)
	{
		for (int i = 0; i < n; i++)
		{
			int minIndex = i;
			for (int j = i; j < n; j++)
			{
				if (arr[j] < arr[minIndex])
				{
					minIndex = j;
				}
			}
			if (i != minIndex)
			{
				swap(arr[i], arr[minIndex]);
			}
		}
		printArr(arr, n);
	}

	/*
	归并排序 分支思想
	*/
	void mergeSort(int * & arr, int n)
	{
		int * tempArr = new int[n];
		internalMergeSort(arr, tempArr, 0, n - 1);
		printArr(arr, n);
	}

	/*
	堆排序
	*/
	void heapSort(int * & arr, int n)
	{
		MyHeap<int> * myHeap = new MyHeap<int>(compareTo2);
		for (int i = 0; i < n; i++)
		{
			myHeap->insert(arr[i]);
		}
		for (int i = 0; i < n; i++)
		{
			arr[i] = myHeap->popMin();
		}

		printArr(arr, n);
	}

	void quickSort(int * & arr, int n)
	{
		internalQuickSort(arr, 0, n - 1);

		printArr(arr, n);
	}

	void bucketSort(int * & arr, int n)
	{
		const int size = 1000;
		int book[size] = {0};
		for (int i = 0; i < n; i++)
		{
			book[arr[i]]++;
		}
		int count = 0;
		int index = 0;
		while (count < size)
		{
			while (book[count] > 0)
			{
				arr[index++] = count;
				book[count]--;
			}
			count++;
		}

		printArr(arr, n);
	}
private:

	void internalQuickSort(int * & arr, int left, int right)
	{
		//递归调用基准
		if (left >= right)
		{
			return;
		}
		//记住left和right
		int lastIndex = right;
		int firstIndex = left;

		//确定枢纽元素 选取left right 和中位数的中间值
		int midIndex = (left + right) / 2;
		int threeIndex = midInThree(arr[left], arr[right], arr[midIndex]);
		int pivotIndex = left;
		if (threeIndex == 1)
		{
			pivotIndex = left;
		}
		else if (threeIndex == 2)
		{
			pivotIndex = right;
		}
		else
		{
			pivotIndex = midIndex;
		}
		int pivot = arr[pivotIndex];

		//将枢纽元素放置在最右边
		swap(arr[lastIndex], arr[pivotIndex]);

		//将元素分离 右边大于枢纽 左边小于枢纽
		right = lastIndex - 1;
		while (true)
		{
			while (arr[right] > pivot) //找到大于等于的停下来
			{
				right--;
			}
			while (arr[left] < pivot) //找到小于等于的停下来
			{
				left++;
			}

			if (left < right) //如果循环没有结束 交换两个哨兵
			{
				swap(arr[left], arr[right]);
			}
			else
			{
				break;
			}
		}
		//交换最后停下来的哨兵和枢纽元素
		swap(arr[left], arr[lastIndex]);

		//递归调用排序枢纽元素两侧的数组
		internalQuickSort(arr, firstIndex, left - 1);
		internalQuickSort(arr, left + 1, lastIndex);
	}

	int midInThree(int a, int b, int c)
	{
		if (a > b)
		{
			if (b > c)
			{
				return 2;
			}
			else
			{
				if (a > c)
				{
					return 3;
				}
				else
				{
					return 1;
				}

			}
		}
		else
		{
			if (a > c)
			{
				return 1;
			}
			else
			{
				if (b > c)
				{
					return 3;
				}
				else
				{
					return 2;
				}

			}
		}
	}
	void internalMergeSort(int * & arr, int * & tempArr, int left, int right)
	{
		if (left < right)
		{
			int center = (left + right) / 2;
			internalMergeSort(arr, tempArr, left, center);
			internalMergeSort(arr, tempArr, center + 1, right);
			merge(arr, tempArr, left, center, center + 1, right);
		}
	}

	void merge(int * & arr, int * & tempArr, int leftPos, int leftEnd, int rightPos, int rightEnd)
	{
		int size = rightEnd - leftPos + 1;
		int tempPos = leftPos;
		while (leftPos <= leftEnd && rightPos <= rightEnd)
		{
			if (arr[leftPos] <= arr[rightPos])
			{
				tempArr[tempPos++] = arr[leftPos++];
			}
			else
			{
				tempArr[tempPos++] = arr[rightPos++];
			}
		}
		if (leftPos <= leftEnd)
		{
			while (leftPos <= leftEnd)
			{
				tempArr[tempPos++] = arr[leftPos++];
			}
		}
		if (rightPos <= rightEnd)
		{
			while (rightPos <= rightEnd)
			{
				tempArr[tempPos++] = arr[rightPos++];
			}
		}
		for (int i = 0; i < size; i++, rightEnd--)
		{
			arr[rightEnd] = tempArr[rightEnd];
		}
	}

	void swap(int & a, int & b)
	{
		if (a == b)
		{
			return;
		}
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}

	void printArr(int * & arr, int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

MySort::MySort()
{
}

MySort::~MySort()
{
}
int compareTo2(int num1, int num2)
{
	return num1 - num2;
}

#endif // !MYSORT_H_
