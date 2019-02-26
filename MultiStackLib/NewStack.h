#pragma once
#include <iostream>
#include "..//StackLib/Stack.h"
using namespace std;

template <class T>
class TNewStack : public TStack<T>
{
public:
	TNewStack(int _size, T* _mas);
	TNewStack(TNewStack<T>& A);
	int GetFreeMem();
	void SetMas(int _size, T* _mas);
	T Get();
	void Put(T _A);
	int GetSize();
	int GetTop();
	~TNewStack();
};

template <class T>
TNewStack<T>::TNewStack(int _size, T* _mas)
{
	if (_size <= 0)
		throw TException("Error. Wrong size.");
	TStack<T>::size = _size;
	TStack<T>::top = 0;
	TStack<T>::mas = _mas;
}

template <class T>
TNewStack<T>::TNewStack(TNewStack<T>& A)
{
	TStack<T>::size = A.size;
	TStack<T>::top = A.top;
	TStack<T>::mas = A.mas;
}

template <class T>
int TNewStack<T>::GetFreeMem()
{
	return TStack<T>::size - TStack<T>::top;
}

template <class T>
void TNewStack<T>::SetMas(int _size, T* _mas)
{
	if (_size <= 0)
		throw TException("Error. Wrong size");
	TStack<T>::size = _size;
	TStack<T>::mas = _mas;
}
template <class T>
int TNewStack<T>::GetTop()
{
	return TStack<T>::top;
}

template <class T>
TNewStack<T>::~TNewStack()
{
  TStack<T>::top = 0;
  TStack<T>::size = 0;
  delete[] TStack<T>::mas;
}

template <class T>
int TNewStack<T>::GetSize()
{
	return TStack<T>::size;
}

template <class T>
T TNewStack<T>::Get()
{
	TStack<T>::top--;
	return TStack<T>::mas[TStack<T>::top];
}
template <class T>
void TNewStack<T>::Put(T _A)
{
	TStack<T>::mas[TStack<T>::top] = _A;
	TStack<T>::top++;
}

