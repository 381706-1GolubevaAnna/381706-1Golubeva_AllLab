#pragma once
#include "..//Exception/Exception.h"
#include "..//QueueLib/Queue.h"

template <class T>
class TArrayList
{
private:

	T * mas;
	int *nextIndex; 
	int *prevIndex; 
	int size; 
	int count;
	int begin;
	int end; 
	TQueue <int> freeElem; 
public:
	TArrayList(int _size = 10); 
	TArrayList(TArrayList<T> &A);
	void PutBegin(T elem); 
	void PutEnd(T elem);  
	T GetBegin(); 
	T GetEnd(); 
	bool IsFull(); 
	bool IsEmpty(); 
};

template <class T>
TArrayList<T>::TArrayList(int _size) : freeElem(_size)
{
	if (_size <= 0)
		throw TException("Error. Negative size.");
	size = _size;
	count = 0; 
	begin = -1; 
	end = -1;
  mas = new T[size];
  nextIndex = new int[size];
	prevIndex = new int[size];
	for (int i = 0; i < size; i++)
	{
		nextIndex[i] = -2;
		prevIndex[i] = -2;
		freeElem.Put(i);
	}
}

template <class T>
TArrayList<T>::TArrayList(TArrayList<T> &A)
{
	begin = A.begin;
	end = A.end;
	size = A.size;
	count = A.count;
	mas = new T[size];

	nextIndex = new int[size];
	prevIndex = new int[size];
	freeElem = A.freeElem;
	for (int i = 0; i < size; i++)
	{
		mas[i] = A.mas[i];
		nextIndex[i] = A.nextIndex[i];
		prevIndex[i] = A.prevIndex[i];
	}
}

template <class T>
void TArrayList<T>::PutBegin(T elem)
{
	if (IsFull())
		throw TException("Error. List is full.");

	int free = freeElem.Get();
	mas[free] = elem;
	nextIndex[free] = begin;
	if (begin != -1)
		prevIndex[begin] = free;
	else
		end = free;
	begin = free;
	count++;
}

template <class T>
void TArrayList<T>::PutEnd(T elem)
{
	if (IsFull())
		throw TException("Error. List is full.");
	int free = freeElem.Get();
	mas[free] = elem;
	if (end != -1)
		nextIndex[end] = free;
	else
	{
		begin = free;
		prevIndex[free] = -1;
	}
	prevIndex[free] = end;
	end = free;
	count++;
}

template <class T>
T TArrayList<T>::GetBegin()
{
	if (IsEmpty())
		throw TException("Error. List is empty.");
	T elem = mas[begin];
	int newBegin = nextIndex[begin];
	freeElem.Put(begin);
	nextIndex[begin] = prevIndex[begin] = -2;
	if (newBegin != -1)
		prevIndex[newBegin] = -1;
	count--;
	begin = newBegin;
	return elem;
}
template <class T>
T TArrayList<T>::GetEnd()
{
	if (IsEmpty())
		throw TException("Error. List is empty.");
	T elem = mas[end];
	int newEnd = prevIndex[end];
	prevIndex[end] = nextIndex[end] = -2;
	freeElem.Put(end);
	end = newEnd;
	if (newEnd != -1)
		nextIndex[newEnd] = -1;
	else
		begin = -1;
	count--;
	return elem;
}

template <class T>
bool TArrayList<T>::IsFull()
{
	if (count == size)
		return true;
	else
		return false;
}

template <class T>
bool TArrayList<T>::IsEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}
