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
	相当于抓牌 手上已近抓了一张arr[0],然后没抓取一张就和已经排序好的前半部分比较
	我这里是升序排序 所以从后往前进行 比当前抓取的牌大的就后移 直到找到合适的位置
	跳出循环 放下抓取的牌 重复进行 直到所有的牌抓完
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
	shell排序 定义一个增量序列【1,....k】 通过递减增量序列 得到每次每隔多少间隔进行交换 消除逆序对
	可以是插入也可以是冒泡
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
	冒泡排序 
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
