#pragma once
#include "List.h"
#include "../Exception/Exception.h"

template <class T>
class TStackList : public TList<T>
{
protected:
	int size_st;
public:
	TStackList<T>(int _size = 10);
	TStackList<T>(TStackList<T> &A);
	~TStackList();
	void Print();
	void Put(T A);
	T Get();
	int GetSize();
	int GetMaxSize();
	bool IsEmpty();
	bool IsFull();
};

template <class T>
TStackList<T>::TStackList(int _size) : TList<T>()
{
	if (_size <= 0)
		throw TException("Error. Wrong size");
	size_st = _size;
}

template <class T>
TStackList<T>::TStackList(TStackList<T> &A) : TList<T>(A)
{
	TList<T>::size = A.size;
}

template<class T>
TStackList<T>::~TStackList()
{}

template <class T>
void TStackList<T>::Put(T A)
{
	if (this->IsFull())
		throw TException("Error. Stack is full.");
	TList<T>::PutBegin(A);
}

template <class T>
T TStackList<T>::Get()
{
	if (this->IsEmpty())
		throw TException("Error. Stack is empty.");
	return TList<T>::GetBegin();
}

template <class T>
int TStackList<T>::GetMaxSize()
{
	return size_st;
}

template<class T>
inline int TStackList<T>::GetSize()
{
	return TList<T>::size;
}

template <class T>
bool TStackList<T>::IsEmpty()
{
	if (TList<T>::size == 0)
		return true;
	return false;
}
template<class T>
bool TStackList<T>::IsFull()
{
	if (TList<T>::size == size_st)
		return true;
	return false;
}

template<class T>
void TStackList<T>::Print()
{
	if (this->IsEmpty())
		throw TException("Stack is empty");
	TList<T>::Print();
}
