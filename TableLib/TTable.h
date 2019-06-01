#pragma once
#include "TElem.h"
#include <iostream>

using namespace std;

template <class T>
class TTable
{
protected:
  TElem<T>* mas;
  TElem<T> not_found;
  int size;
  int count;

public:

  TTable (int _size = 0);
  TTable (TTable& A);
  
  void SetSize (int _size);
  void SetCount (int _count);
  TElem<T>* GetMas();
  int GetSize();
  int GetCount();

  TElem<T>& Search (string _key);
  T operator[](string _key);
  void Put (string _key, T _data);
  void Put (TElem<T> A);
  void Del (string _key);
  
  bool IsFull ();
  bool IsEmpty();

  friend ostream & operator << ( ostream &ostr, TTable &table)
  {
    for (int i = 0; i < table.GetCount(); i++)
      ostr << table.mas[i]<<"\n";
    return ostr;
  }

};

template <class T>
TViewTable<T>::TTable(int _size)
{
  if (_size < 0)
    throw -1;
  else
  {
    size = _size;
    mas = new TElem<T>[size];
    count = 0;
    for (int i = count; i < size; i++)
      mas[i] = not_found;
}
}

template <class T>
TViewTable<T>::TTable(TTable& A)
{
  size = A.size;
  count = A.count;
  mas = new TElem<T> [size];
  for (int i = 0; i < count; i++)
    mas[i] = A.mas[i];
  for (int i = count; i < size; i++)
    mas[i] = not_found;
}

template <class T>
void TTable<T>::SetSize(int _size)
{
  size = _size;
}

template <class T>
void TTable<T>::SetCount(int _count)
{
  count = _count;
}

template <class T>
int TTable<T>::GetSize()
{
  return size;
}

template <class T>
int TTable<T>::GetCount()
{
  return count;
}

template <class T>
TElem<T>* TTable<T>::GetMas()
{
  return mas;
}


template <class T>
void TTable<T>::Put(string _key, T _data)
{
  if (IsFull())
    throw -1;
  
    if (Search(_key) != not_found)
      throw "Element already exist";
    mas[count].SetKey(_key);
    mas[count].SetData(_data);
    count++;
    
}

template <class T>
void TTable<T>::Put(TElem<T> A)
{
  if (IsFull())
    throw -1;
  if (Search(A.GetKey()) != not_found)
    throw -1;
  else
   {
    mas[count] = A;
    count++;
   }
  
}

template <class T>
void TTable<T>::Del(string _key)
{
  if (IsEmpty())
    throw -1;
  TElem<T>& tmp = Search(_key);
  if (tmp != not_found)
    tmp = not_found;
}

template <class T>
TElem<T>& TTable<T>::Search(string _key)
{
  for (int i = 0; i < count; i++)
    if (mas[i].GetKey() == _key)
      return mas[i];
  return not_found;
}

template <class T>
T TTable<T>::operator [] (string _key)
{
  TElem<T>& temp = Search(_key);
  if (temp == not_found)
  {
    if (IsFull())
      throw -1;
    else
    {
      TElem<T> elem(_key, NULL);
      Put(elem);
      count++;
      return mas[count-1].GetData();
    }
  }
  else return temp.GetData();
}

template <class T>
bool TTable<T>::IsFull()
{
  return (size == count);
}

template <class T>
bool TTable<T>::IsEmpty()
{
  return (count == 0);
}
