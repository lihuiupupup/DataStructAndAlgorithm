#pragma once
#ifndef MYSORT_H_
#define MYSORT_H_
#include <iostream>
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
	void insertSort(int * & arr,int n)
	{
		for (int i = 1 ;i < n ; i ++)
		{
			int cur = arr[i];
			int j = i - 1;
			for ( ; j >= 0 ;j--)
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
			arr[j+1] = cur;
		}

		printArr(arr, n);
	}

	/*
	shell���� ����һ���������С�1,....k�� ͨ���ݼ��������� �õ�ÿ��ÿ�����ټ�����н��� ���������
	�����ǲ���Ҳ������ð��
	*/
	void shellSort(int * & arr, int n)
	{
		for (int gap = n / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < n; i += gap)
			{
				int cur = arr[i];
				int j = i;
				for (; j >= gap && arr[j-gap] > cur; j-=gap)
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
				if (arr[j] > arr[j+1])
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
private:
	void swap(int & a, int & b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}

	void printArr(int * & arr, int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << endl;
		}
	}
};

MySort::MySort()
{
}

MySort::~MySort()
{
}


#endif // !MYSORT_H_
