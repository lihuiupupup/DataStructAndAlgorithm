#pragma once
#ifndef MYQUEUE_H_
#define MYQUEUE_H_

using namespace std;

template<typename T>
class MyQueue
{
public:
	MyQueue();
	~MyQueue();
	MyQueue(const MyQueue<T> & s)
	{
		operator=(s);
	}
	MyQueue & operator=(MyQueue<T> & s)
	{
		if (this == &s)
		{
			return s;
		}
		delete[] data;
		this->size = s.size;
		this->front = s.front;
		this->back = s.back;
		this->capacity = s.capacity;
		data = new T[capacity];
		for (size_t i = 0; i < capacity; i++)
		{
			data[i] = s.data[i];
		}
		return *this;
	}
	void push(const T & t)
	{
		if (size == capacity)
		{			
			resize(2 * size);
		}
		if (back == capacity)
		{
			back = 0;
		}		
		data[back] = t;
		back++;
		size++;
	}

	T & pop()
	{
		int temp = front;
		front++;
		if (front == capacity)
		{
			front = 0;
		}
		size--;
		return data[temp];
	}

	int getSize()
	{
		return size;
	}

	int getCapacity()
	{
		return capacity;
	}

	bool isEmpey()
	{
		return size == 0;
	}

private:
	T * data;
	int size = 0;
	int front = 0;
	int back = 0;
	enum 
	{
		INIT_CAPACITY = 2
	};
	int capacity = INIT_CAPACITY;
	void resize(int newSize)
	{
		cout << "resise:" << newSize << endl;
		T * oldData = data;
		
		
		data = new T[newSize];
		capacity = newSize;
		int count = 0;
		int oldSize = size;
		while (size > 0)
		{
			if (front == oldSize)
			{
				front = 0;
			}
			data[count++] = oldData[front++];
			size--;
		}
		delete[] oldData;
		front = 0;
		back = oldSize;
		size = oldSize;
		cout << "szie data ::" << data[0] << " " << data[1] << " " << size << " " << front << " " << back << endl;
	}
};

template<typename T>
MyQueue<T>::MyQueue()
{
	data = new T[capacity];
}

template<typename T>
MyQueue<T>::~MyQueue()
{
	delete[] data;
}
#endif // !MYQUEUE_H_
