#pragma once
#ifndef MYHEAP_H_
#define MYHEAP_H_
#include "MyVector.h"
using namespace std;

/*
最小堆 提供了插入和弹出最小元素
*/
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
		int tempPos = ++curSize; // 堆大小增加 且为当前节点
		if (tempPos != 1) //不是根元素插入
		{
			while (comparator(t, (*data)[tempPos / 2]) < 0) //比较最后元素和他的父亲节点的大小 如果小于
			{
				(*data)[tempPos] = (*data)[tempPos / 2]; // 父亲节点往下移 
				tempPos /= 2; //当前节点移到父亲节点
				if (tempPos == 1) // 如果已是根节点 跳出循环
				{
					break;
				}
			}
		}
		
		(*data)[tempPos] = t; //当前节点保存插入的元素
		return true;
	}

	T  popMin()
	{
		T  result = (*data)[1]; //保存结果
		T  last = (*data)[curSize]; // 由于删除元素 需要为最后元素找合适位置 所以保存起来
		int tempIndex = 1; 
		int tempIndex2 = 1;
		T  temp = (*data)[1];

		//比较当前节点和最后节点的大小 如果当前节点小于最后节点 则当前节点信息上移 直到找到合适位置
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

