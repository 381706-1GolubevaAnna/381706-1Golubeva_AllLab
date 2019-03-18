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
        ~TArrayList();
	void PutBegin(T elem); 
	void PutEnd(T elem);  
	T GetBegin(); 
	T GetEnd(); 
	void Put(int n, T elem);  
	T Get(int n);
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

template<class T>
inline TArrayList<T>::~TArrayList()
{
  delete[] mas;
  delete[] nextIndex;
  delete[] prevIndex;
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
template<class T>
void TArrayList<T>::Put(int n, T elem)
{
	if (IsFull())
		throw "Error. List is full";
	if (n < 1 || n > count - 1)
		throw "Error. Wrong index";
	int free = freeElem.Get();
	mas[free] = elem;
	int temp1 = begin;
	int temp2 = nextIndex[begin];
	for (int i = 0; i < n - 1; i++)
	{
		temp1 = temp2;
		temp2 = nextIndex[temp2];
	}
	nextIndex[free] = temp2;
	nextIndex[temp1] = free;
	prevIndex[free] = temp1;
	prevIndex[temp1] = free;
	count++;
}

template<class T>
T TArrayList<T>::Get(int n)
{
	if (IsEmpty())
		throw "Error. List is empty";
	if (n < 1 || n > count - 1)
		throw "Error. Wrong index";
	int temp = begin;
	for (int i = 0; i < n; i++)
		temp = nextIndex[temp];
	nextIndex[prevIndex[temp]] = nextIndex[temp];
	prevIndex[nextIndex[temp]] = prevIndex[temp];
	T elem = mas[temp];
	freeElem.Put(temp);
	count--;
	return elem;
}
