#pragma once
#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_
using namespace std;
template<typename T>
#include <exception>
class MyVector
{
public:
	//����
	MyVector(int initSize = 0) :size(initSize), capacity(MyEnum::INITCAPCITY)
	{
		data = new T[MyEnum::INITCAPCITY];
	}
	//����
	~MyVector()
	{
		delete[] data;
	}
	//��������
	MyVector(const MyVector<T> & t) :data(NULL)
	{
		operator=(t);
	}
	//��ֵ����
	MyVector & operator=(const MyVector<T> & t)
	{
		if (*this == t)
		{
			return;
		}
		delete[] data;
		this->capacity = t.getCapacity();
		this-> size = t.getSize();
		data = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = t[i];
		}
		return *this;
	}

	//��������
	T & operator[](const int i)
	{
		return data[i];
	}
	
	//׷��Ԫ��
	void push_back(const T &t)
	{
		if (size == capacity)
		{
			resize(2 * size + 1);
		}
		data[size++] = t;
	}
	//ɾ��Ԫ��
	void pop_back()
	{
		size--;
	}

	//�������һ��Ԫ��
	T & back()
	{
		if (size == 0)
		{
			throw exception();

		}
		return data[size - 1];
	}

	int getCapacity()
	{
		return capacity;
	}

	int getSize()
	{
		return size;
	}
private:
	int size;
	int capacity;
	T  * data;
	enum MyEnum
	{
		INITCAPCITY = 4
	};

	//����
	void resize(int newCapacity)
	{
		cout << "resize" << newCapacity << endl;
		if (newCapacity < size)
		{
			return;
		}

		T * oldArr = data;
		data = new T[newCapacity];
		capacity = newCapacity;
		for (int i = 0; i < size; i++)
		{
			data[i] = oldArr[i];
		}
		delete[] oldArr;
	}
};

#endif // !MY_VECTOR_H_

