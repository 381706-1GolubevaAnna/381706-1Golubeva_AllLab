#pragma once
#include "../StackLib/Stack.h"

template <class T>
class TQueue : public TStack <T> 
{
  protected:
  int start;
  int count;
  public:
  TQueue(int n = 0);
  TQueue(TQueue <T> &q);
  virtual ~TQueue();
  void Put(T a);
  T Get();
  T GetTop();
  bool IsFull();
  bool IsEmpty();
  void PrintQueue();
};

template <class T>
TQueue<T>::TQueue(int n) : TStack<T>(n) 
{
  start = 0;
  count = 0;
}

template <class T>

TQueue<T>::TQueue(TQueue<T> &q) : TStack<T>(q)
{
  start = q.start;
  count = q.count;
}

template <class T>
TQueue<T>::~TQueue() {}

template <class T>
void TQueue<T>::Put(T a) 
{
  if (IsFull())
    throw TException("Error. Queue is full.");
  else 
  {
    TStack<T>::Put(a);
    TStack<T>::top = TStack<T>::top % TStack<T>::size;
    count++;
  }
}
template <class T>
T TQueue<T>::GetTop()
{
  return TStack<T>::mas[start];
}

template <class T>
T TQueue<T>::Get()
{
  if (IsEmpty())
    throw TException("Error.Queue is empty");
  else 
  {
    T temp = TStack<T>::mas[TStack<T>::top];
    start = (start + 1) % TStack<T>::size;
    count--;
    return temp;
  }
}

template <class T>
bool TQueue<T>::IsFull() 
{
  if (count == TStack<T>::size)
    return true;
  else
    return false;
}

template <class T>
bool TQueue<T>::IsEmpty()
{
  if (count == 0)
    return true;
  else
    return false;
}

template <class T>
void TQueue<T>::PrintQueue()
{
  int i = TStack<T>::top;
  for (int j = 1; j <= count; j++)
  {
    i = (i + 1) % TStack<T>::size;
    cout << "\t" << TStack<T>::mas[i];
  }
}
