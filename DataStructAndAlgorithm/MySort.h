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
	�൱��ץ�� �����ѽ�ץ��һ��arr[0],Ȼ��ûץȡһ�žͺ��Ѿ�����õ�ǰ�벿�ֱȽ�
	���������������� ���ԴӺ���ǰ���� �ȵ�ǰץȡ���ƴ�ľͺ��� ֱ���ҵ����ʵ�λ��
	����ѭ�� ����ץȡ���� �ظ����� ֱ�����е���ץ��
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
	shell���� ����һ���������С�1,....k�� ͨ���ݼ��������� �õ�ÿ��ÿ�����ټ�����н��� ���������
	�����ǲ���Ҳ������ð�� ���ȶ�
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
	ð������
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
	ѡ������ ���ȶ�
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
	�鲢���� ��֧˼��
	*/
	void mergeSort(int * & arr, int n)
	{
		int * tempArr = new int[n];
		internalMergeSort(arr, tempArr, 0, n - 1);
		printArr(arr, n);
	}

	/*
	������
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
		//�ݹ���û�׼
		if (left >= right)
		{
			return;
		}
		//��סleft��right
		int lastIndex = right;
		int firstIndex = left;

		//ȷ����ŦԪ�� ѡȡleft right ����λ�����м�ֵ
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

		//����ŦԪ�ط��������ұ�
		swap(arr[lastIndex], arr[pivotIndex]);

		//��Ԫ�ط��� �ұߴ�����Ŧ ���С����Ŧ
		right = lastIndex - 1;
		while (true)
		{
			while (arr[right] > pivot) //�ҵ����ڵ��ڵ�ͣ����
			{
				right--;
			}
			while (arr[left] < pivot) //�ҵ�С�ڵ��ڵ�ͣ����
			{
				left++;
			}

			if (left < right) //���ѭ��û�н��� ���������ڱ�
			{
				swap(arr[left], arr[right]);
			}
			else
			{
				break;
			}
		}
		//�������ͣ�������ڱ�����ŦԪ��
		swap(arr[left], arr[lastIndex]);

		//�ݹ����������ŦԪ�����������
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
