#pragma once

template <class T>
class TElem
{
public:
	T data;
	TElem<T>* next;

	TElem(T _data = 0, TElem<T>* _next = 0);
	TElem(TElem<T> & A);
	virtual ~TElem();
	T GetData();
	TElem<T>* GetNext();
	void SetData(T _data);
	void SetNext(TElem <T>* _next);
};

template <class T>
TElem<T>::TElem(T _data, TElem<T>* _next)
{
	data = _data;
	next = _next;
}

template <class T>
TElem<T>::TElem(TElem<T> &A)
{
	data = A.data;
	next = A.next;
}

template <class T>
TElem<T>::~TElem() {}

template <class T>
T TElem<T>::GetData()
{
	return data;
}

template <class T>
TElem<T>* TElem<T>::GetNext()
{
	return next;
}

template <class T>
void TElem<T>::SetData(T _data)
{
	data = _data;
}

template <class T>
void TElem<T>::SetNext(TElem<T>* _next)
{
	next = _next;
}
