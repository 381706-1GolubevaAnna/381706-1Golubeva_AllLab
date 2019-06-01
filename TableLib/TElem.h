#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T>
class TElem
{
protected:
  string key;
  T data;

public:

  TElem (string _key = "", T _data = 0);
  TElem (TElem &A);
  
  void SetKey(string _key);
  void SetData(T _data);
  string GetKey();
  T GetData();
  
  TElem& operator = (TElem &A);
  bool operator == (TElem &A);
  bool operator != (TElem &A);
  bool operator > (TElem<T>&A);
	bool operator < (TElem<T>&A);

  template <class T1>
  friend istream & operator>>( istream &istr, TElem<T1> &elem)
  {
    istr>>elem.key;
    istr>>elem.data;
    return istr;
  }

  template <class T1>
  friend ostream & operator<<( ostream &ostr, TElem<T1> &elem)
  {    
    ostr<<elem.GetKey()<<"\t";
    ostr<<elem.GetData()<<"\t";
    return ostr;
  }
};


template <class T>
TElem<T>::TElem (string _key, T _data)
{
  key = _key;
  data = _data;
}

template <class T>
TElem<T>::TElem(TElem &A)
{
  key = A.key;
  data = A.data;
}

template <class T>
void TElem<T>::SetKey(string _key)
{
  key = _key;
}

template <class T>
void TElem<T>::SetData(T _data)
{
  data = _data;
}

template <class T>
string TElem<T>::GetKey()
{
  return key;
}

template <class T>
T TElem<T>::GetData()
{
  return data;
}

template <class T>
TElem<T>& TElem<T>::operator = (TElem &A)
{
  key = A.key;
  data = A.data;
  return *this;
}

template <class T>
bool TElem<T>::operator == (TElem &A)
{
  return ((key == A.key) && (data == A.data));
}

template <class T>
bool TElem<T>::operator != (TElem &A)
{
  return ((key != A.key) || (data != A.data));
}

template <class T>
bool TScanElem<T>::operator>(TElem<T>& A)
{
	return (key > A.key);
}

template <class T>
bool TScanElem<T>::operator<(TElem<T>& A)
{
	return (key < A.key);
}
