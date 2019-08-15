#pragma once
#ifndef MYHEAP_H_
#define MYHEAP_H_
#include "MyVector.h"
using namespace std;

template<typename T>
class MyHeap
{
public:
	typedef int(*Comparator)(T t, T t2);

	MyHeap(Comparator comp):comparator(comp)
	{
		this->data = new MyVector<T>;
	}
	~MyHeap()
	{
		delete data;
	}
	MyHeap(const MyHeap & heap)
	{
		*this = heap;
	}

	MyHeap & operator=(const MyHeap & heap)
	{
		this->curSize = heap.curSize;
		this->data = heap.data;
		return *this;
	}
	
	int getSize()
	{
		return curSize;
	}

	bool insert(T t)
	{
		int tempPos = ++curSize;
		if (tempPos != 1)
		{
			while (comparator(t, (*data)[tempPos / 2]) < 0)
			{
				(*data)[tempPos] = (*data)[tempPos / 2];
				tempPos /= 2;
				if (tempPos == 1)
				{
					break;
				}
			}
		}
		
		(*data)[tempPos] = t;
		return true;
	}

	T  popMin()
	{
		T  result = (*data)[1];
		T  last = (*data)[curSize];
		int tempIndex = 1;
		int tempIndex2 = 1;
		T  temp = (*data)[1];
		
		while (comparator(temp,last) < 0)
		{
			if (2 * tempIndex > curSize)
			{
				break;
			}
			else if (curSize == 2 * tempIndex)
			{
				temp = (*data)[2 * tempIndex];
				tempIndex2 = 2 * tempIndex;
			} 
			else
			{
				tempIndex2 = tempIndex;
				if (comparator((*data)[2 * tempIndex], (*data)[2 * tempIndex + 1]) < 0)
				{
					temp = (*data)[2 * tempIndex];
					tempIndex2 = 2 * tempIndex;
				}
				else
				{
					temp = (*data)[2 * tempIndex + 1];
					tempIndex2 = 2 * tempIndex + 1;
				}
			}
			
			(*data)[tempIndex] = temp;
			tempIndex = tempIndex2;
		}
		(*data)[tempIndex] = last;
		curSize--;
		return result;
	}

private:
	Comparator comparator;
	int curSize = 0;
	MyVector<T> * data;
};

#endif // !MYHEAP_H_

