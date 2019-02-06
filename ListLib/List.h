#pragma once
#include <iostream>
#include "Elem.h"
#include "Exception.h"

using namespace std;

template <class T>
class TList
{
protected:
	TElem<T>* begin;          
	int size;              
public:
	TList();                    
	TList(TList<T> &A);        
	virtual ~TList();         
	int GetSize();     
	bool IsFull();
	bool IsEmpty();
	void Print(); 
	void PutBegin(T A);    
	void PutEnd(T A);       
	T GetBegin();               
	T GetEnd();                            
};

template <class T>
TList<T>::TList()
{
	begin = 0;
	size = 0;
}

template <class T>
TList<T>::TList(TList<T> &A)
{
	
	TElem<T>* a = A.begin, b;
	size = A.size;
	if (A.begin == 0)
		begin = 0;
	else
	{
		begin = new TElem<T>(*A.begin);
		b = begin;
		while (a->GetNext() != 0)
		{
			b->SetNext(new TElem<T>(*(a->GetNext())));
			a = a->GetNext();
			b = b->GetNext();
		}
	}
}

template <class T>
TList<T>::~TList()
{
	while (begin != 0)
	{
		TElem<T>* temp = begin;
		begin = begin->GetNext();
		delete temp;
	}
}

template<class T>
int TList<T>::GetSize()
{
	return size;
}

template <class T>
void TList<T>::PutBegin(T A)
{
	if (this->IsFull())
		throw TException("Error. List is full.");
	if (begin == 0)
	{
		TElem<T>* temp = new TElem<T>(A, 0);
		begin = temp;
	}
	else
	{
		TElem<T>* temp = new TElem<T>(A, begin);
		begin = temp;
	}
	size++;
}

template <class T>
void TList<T>::PutEnd(T A)
{
	if (this->IsFull())
		throw TException("Error. List is full.");
	if (begin != 0)
	{
		TElem<T>* a = begin;
		while (a->GetNext() != 0)
			a = a->GetNext();
		a->SetNext(new TElem <T>(A, 0));
	}
	else
		begin = new TElem<T>(A, 0);
	size++;
}

template <class T>
T TList<T>::GetBegin()
{
	if (IsEmpty())
		throw TException("Error. List is empty.");
	else
	{
		TElem<T>* a = begin;
		T temp = begin->TElem<T>::GetData();
		begin = begin->TElem<T>::GetNext();
		delete a;
		size--;
		return temp;
	}
}

template <class T>
T TList<T>::GetEnd()
{
	if (IsEmpty())
		throw TException("Error. List is Empty.");
	else
	{
		size--;
		TElem<T>* a = begin;
		TElem<T>* b = begin->GetNext();
		if (b == 0)
		{
			T temp = a->TElem<T>::GetData();
			delete a;
			begin = 0;
			return temp;
		}
		else
		{
			while (b->GetNext() != 0)
			{
				a = b;
				b = b->GetNext();
			}
			T temp = b->GetData();
			delete b;
			a->SetNext(0);
			return temp;
		}
	}
}

template<class T>
inline void TList<T>::Print()
{
	if (begin == 0)
		throw TException("Error. List is Empty.");
	else
	{
		TElem<T>* a = begin;
		while (a->GetNext() != 0)
		{
			cout << a->GetData() << " ";
			a = a->GetNext();
		}
		cout << a->GetData() << " ";
	}
}
template <class T>
bool TList<T>::IsFull()
{
	try
	{
		TElem<T>* A = new TElem<T>();
		if (A == NULL)
			return false;
		else
		{
			delete A;
			return true;
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}

template <class T>
bool TList<T>::IsEmpty()
{
	if (begin == 0)
		return true;
	return false;
}

