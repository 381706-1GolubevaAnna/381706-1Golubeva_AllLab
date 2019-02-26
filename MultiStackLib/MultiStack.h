#pragma once
#include "NewStack.h"
#include "Exception.h"

template <class T>
class TMStack
{
protected:
	int size;
	T* mas;
	int n;
	TNewStack<T>** h;
	int GetFree();
	void Repack(int n);

public:
	TMStack(int _n, int _size);
	TMStack(TMStack &A);
	~TMStack();
	int GetSize();
	T Get(int _n);
	void Set(int _n, T _elem);
	bool IsFull(int _n);
	bool IsEmpty(int _n);
};

template <class T>
TMStack<T>::TMStack(int _n, int _size)
{
	if (_n < 0 || _size < 0)
		throw TException("Error.Negative leight.");
	if (size == 0)
	{
		mas = NULL;
		h = NULL;
	}
	n = _n;
	size = _size;
	h = new TNewStack<T>*[n];
	mas = new T[size];
	int* A = new int[n];
	for (int i = 0; i < n; i++)
		A[i] = int(size / n);
	A[0] += size % n;
	h[0] = new TNewStack<T>(A[0], &mas[0]);
	for (int i = 1; i < n; i++)
		h[i] = new TNewStack<T>(A[i], &mas[A[0]] + ((i - 1)*A[i]));
}

template <class T>
TMStack<T>::TMStack(TMStack &A)
{
	size = A.size;
	n = A.n;
	if (size == 0)
	{
		mas = NULL;
		h = NULL;
	}
	else
	{
		mas = new T[size];
		for (int i = 0; i < n; i++)
			mas[i] = A.mas[i];
		h = new TNewStack<T>*[n];
		int* p;
		p = new int[n];
		for (int i = 0; i < n; i++)
			p[i] = A.h[i]->GetSize();
		T** k = new T*[n];
		k[0] = mas;
		for (int i = 1; i < n; i++)
			k[i] = p[i - 1] + k[i - 1];
		for (int i = 0; i < n; i++)
		{
			h[i] = new TNewStack<T>(*A.h[i]);
			h[i]->SetMas(p[i], k[i]);
		}
		delete[] p;
	}
}
template <class T>
TMStack<T>::~TMStack()
{
	
	for (int i = 0; i < n; i++)
	{
		delete h[i];
		h[i]=NULL;
	}
	if (h!=NULL)
	{
	delete [] h;
	h=NULL;
	}
	if (mas!=NULL)
	{
	delete[] mas;
	mas=NULL;
	}
	n = 0;
	size = 0;
}

template <class T>
int TMStack<T>::GetSize()
{
	return size;
}

template<class T>
void TMStack<T>::Set(int _n, T _elem)
{
	if (_n < 0 || _n >= n)
		throw TException("Error. Wrong index");
	if (IsFull(_n))
		Repack(_n);
	h[_n]->TStack<T>::Put(_elem);
}

template<class T>
T TMStack<T>::Get(int _n)
{
	if (_n < 0 || _n >= n)
		throw TException("Error.Wrong index");
	if (IsEmpty(_n))
		throw TException("Empty");
	return h[_n]->TStack<T>::Get();
}

template<class T>
bool TMStack<T>::IsFull(int _n)
{
	if (_n < 0 || _n >= n)
		throw TException("Error. Wrong index");
	return (h[_n]->GetFreeMem() == 0);
}

template<class T>
bool TMStack<T>::IsEmpty(int _n)
{
	if (_n < 0 || _n >= n)
		throw TException("Error. Wrong index");
	return (h[_n]->GetFreeMem() == h[_n]->GetSize());
}

template <class T>
int TMStack<T>::GetFree()
{
	int count = 0;
	for (int i = 0; i < n; i++)
		count += h[i]->GetFreeMem();
	return count;
}

template <class T>
void TMStack<T>::Repack(int _n)
{
	int freeMem = GetFree();
	if (freeMem == 0)
	{
		throw TException ("Error.");
		
	}
	int add_ev = freeMem / n;
	int add_full = freeMem % n;
	int* new_size = new int[n];
	T** new_start = new T*[n];
	T** old_start = new T*[n];

	for (int i = 0; i < n; i++)
		new_size[i] = add_ev + h[i]->TNewStack<T>::GetTop();
	new_size[_n] += add_full;
	new_start[0] = old_start[0] = mas;
	for (int i = 1; i < n; i++)
	{
		new_start[i] = new_start[i - 1] + new_size[i - 1];
		old_start[i] = old_start[i - 1] + h[i - 1]->TNewStack<T>::GetSize();
	}
	for (int i = 0; i < n; i++)
	{
		if (new_start[i] <= old_start[i])
			for (int j = 0; j < h[i]->TNewStack<T>::GetTop(); j++)
				new_start[i][j] = old_start[i][j];
		else
		{
			int s;
			for (s = i + 1; s < n; s++)
				if (new_start[s] <= old_start[s])
					break;
			for (int j = s - 1; j >= i; j--)
				for (int r = h[j]->TNewStack<T>::GetTop() - 1; r >= 0; r--)
					new_start[j][r] = old_start[j][r];
			i = s - 1;
		}
	}
	for (int i = 0; i < n; i++)
		h[i]->TNewStack<T>::SetMas(new_size[i], new_start[i]);
	delete[] new_size;
	delete[] new_start;
	delete[] old_start;
}
