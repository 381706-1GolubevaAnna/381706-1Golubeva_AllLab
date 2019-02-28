#pragma once
#include <iostream>
#include <cmath>
#include "../Exception/Exception.h"
using namespace std;
template <class T>
class TVector 
{
protected:
  T *vector;
  int size;
public:
  TVector<T>(int size = 0);
  TVector<T>(const TVector<T> &v);
  virtual ~TVector<T>();
  bool operator==(const TVector<T> &v) const;
  bool operator!=(const TVector<T> &v) const;
  TVector& operator=(const TVector<T> &v);
  int GetSize();
  TVector operator++();
  TVector operator++(int); 
  TVector operator--(); 
  TVector operator--(int); 
  TVector operator +(T h);
  TVector operator -(T h);
  TVector operator *(T h); 
  TVector operator +(const TVector<T> &v);
  TVector operator -(const TVector<T> &v);
  T operator *(const TVector<T> &v);
  template <class FriendT> friend istream& operator>>(istream &istr, TVector<FriendT> &v);
  template <class FriendT> friend ostream& operator<<(ostream &ostr, const TVector<FriendT> &v);
};


template <class T>
TVector<T> ::TVector(int n)
{
  if (n < 0)
    throw TException("Error. Negative size.");
  else 
  if (n == 0)
    {
      size = 0;
      vector = NULL;
    }
  else
  {
    vector = new T[n];
    size = n;
    for (int i = 0; i < n; i++)
    vector[i] = 0;
  }
}

template <class T>
TVector<T> ::TVector (const TVector<T> &v)
{
  size = v.size;
  if (size == 0)
    vector = NULL;
  else
  {
    vector = new T[v.size];
    for (int i = 0; i < size; i++)
      vector[i] = v.vector[i];
  }
}

template <class T>
TVector<T> ::~TVector()
{
  delete[] vector;
  vector = NULL;
  size = 0;
}

template<class T>
int TVector<T>::GetSize()
{ 
  return size; 
}

template <class T>
TVector<T> & TVector<T> ::operator =(const TVector<T> &v)
{
 if (this == &v)
	return *this;
 delete[] vector;
 size=v.size;
 vector = new T[size];
for (int i = 0; i < size; i++)
	(*this)[i] = v.vector[i];
return *this;
}

template <class T>
TVector<T> TVector<T> :: operator+(const TVector<T> &v)
{
  if (size!=v.size)
    throw TException("Error. Different dimensions.");
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp.vector[i] = vector[i] + v.vector[i];
  return temp;
}

template <class T>
TVector<T> TVector<T> :: operator-(const TVector<T> &v)
{
  if (size != v.size)
    throw TException("Error. Different dimensions.");
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp.vector[i] = vector[i] - v.vector[i];
  return temp;
}

template <class T>
T TVector<T> :: operator*(const TVector<T> &v)
{
  if (size != v.size) 
    throw TException("Error. Different dimensions.");
  T temp=0;
  for (int i = 0; i < size; i++)
    temp+= vector[i]*v.vector[i];
  return temp;
}

template <class T>
TVector<T> TVector<T> :: operator+ (T h)
{
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp.vector[i] = vector[i]+h;
  return temp;
}

template <class T>
TVector<T> TVector<T> :: operator- (T h)
{
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp.vector[i] = vector[i] - h;
  return temp;
}

template <class T>
TVector<T> TVector<T> :: operator* (T h)
{
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp.vector[i] = vector[i] * h;
  return temp;
}

template<class T>
bool TVector<T> ::operator==(const TVector<T> &v) const
{
  if (size != v.size)
    return 0;
  else
  for (int i = 0; i < size; i++)
    if (vector[i] != v.vector[i])
    {
      return 0;
    }
   return 1;
}

template <class T>
bool TVector<T> :: operator!=(const TVector<T> &v) const
{
  return !(*this == v);
}

template<class T>
TVector<T> TVector<T> ::operator++()
{
  for (int i = 0; i < size; i++)
    vector[i] = vector[i] + 1;
  return *this;
}

template<class T>
TVector<T> TVector<T> ::operator++(int)
{
  TVector<T> temp(*this);
  for (int i = 0; i < size; i++)
    vector[i] = vector[i] + 1;
  return temp;
}

template<class T>
TVector<T> TVector<T> ::operator--()
{
  for (int i = 0; i < size; i++)
    vector[i] = vector[i] - 1;
  return *this;
}

template<class T>
TVector<T> TVector<T> ::operator--(int)
{
  TVector<T> temp(*this);
  for (int i = 0; i < size; i++)
    vector[i] = vector[i] - 1;
  return temp;
}
template<class FriendT>
istream & operator >>(std::istream &istr, TVector<FriendT> &v)
{
  for (int i = 0; i < v.size; i++)
    istr >> v.vector[i];
  return istr;
}

template<class FriendT>
ostream & operator <<(std::ostream &ostr,const TVector<FriendT> &v)
{
  for (int i = 0; i < v.size; i++)
    ostr << v.vector[i] <<"\t";
  return ostr;
}

