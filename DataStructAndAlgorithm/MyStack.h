#pragma once
#ifndef MYSTACK_H_
#define MYSTACK_H_
#include "MyVector.h"
#include <exception>
using namespace std;

template<typename T>
class MyStack
{
public:
	MyStack();
	~MyStack();
	void push(T t)
	{
		data->push_back(t);
		++topIndex;
	}

	T pop()
	{
		if (topIndex == -1)
		{
			throw exception("is empty");
		}
		topIndex--;
		return (*data).pop_back();
	}

	T top()
	{
		return (*data)[topIndex];
	}

	int size()
	{
		return topIndex + 1;
	}

	bool isEmpty()
	{
		return topIndex == -1;
	}

private:
	MyVector<T> * data;
	int topIndex = -1;
};

template<typename T>
MyStack<T>::MyStack()
{
	data = new MyVector<T>();
}
template<typename T>
MyStack<T>::~MyStack()
{
	delete data;
}
#endif // !MYSTACK_H_
