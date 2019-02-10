#pragma once
#include <iostream>
#include "../VectorLib/VectorLib.h"
using namespace std;

template <class T>
class TMatrix :public TVector<TVector<T> > 
{
public:
  TMatrix(int n = 10);
  TMatrix(const TMatrix<T> &A);
  TMatrix(const TVector<TVector<T> > &A);
  TVector<T>& operator [] (int i);
  TMatrix<T>& operator=(TVector<TVector<T> > &A);
  TMatrix operator +(TMatrix<T> &A);
  TMatrix operator -(TMatrix<T> &A);
  TMatrix operator*(TMatrix<T> &A);
  TMatrix operator/(TMatrix<T> &A);
  bool operator ==(const TMatrix<T> &A);
  bool operator !=(const TMatrix<T> &A);
  template <class FriendT> friend istream& operator>>(istream &istr, TMatrix<FriendT> &A);
  template <class FriendT> friend ostream & operator<<(ostream &ostr, const TMatrix<FriendT> &A);
};

template <class T>
TVector<T>& TMatrix<T>::operator[](int i)
{
	if (0=< i < this->size)
			return this->vector[i];
		else throw TException("Error");

}

template <class T>
TMatrix<T> ::TMatrix(int n) : TVector<TVector<T> >(n)
{
  if (n < 0||n > 1000)  
    throw TException("Error. Negative or too large size of matrix.");
  else
  {
    for (int i = 0; i < n; i++)
      this->vector[i] = TVector <T>(n - i);
  }
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &A) :TVector<TVector<T> >(A) {}

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &A) : TVector<TVector<T> >(A) {}

template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &A)
{
  return TVector<TVector<T> >::operator==(A);
}

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &A)
{
  return TVector<TVector<T> >::operator!=(A);
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(TVector<TVector<T> > &A)
{
  TVector<TVector<T> >::operator=(A);
  return *this;
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(TMatrix<T> &A)
{
  if (this->size!= A.size)
    throw TException("Error. Different dimensions.");
  else
    return TVector<TVector<T> > :: operator+(A);
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(TMatrix<T> &A)
{
  if (this->size= A.size)
    return TVector<TVector<T> > :: operator-(A);
  else
    throw TException("Error. Different dimensions.");
 
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(TMatrix<T> &A)
{
  if (this->size!= A.size)
    throw TException("Error. Different dimensions.");
  TMatrix <T> temp(this->size);
  for (int i = 0; i <this->size; i++)
    for (int j = i; j <this->size; j++)
    {
      for (int r = i; r <= j; r++)
	temp.vector[i][j - i] += this->vector[i][r - i] * A.vector[r][j - r];
    }
  return temp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator/(TMatrix<T> &A)
{
  if (this->size!= A.size)
    throw TException("Error. Different dimentions");	
  TMatrix <T> copyA(A);
  TMatrix <T> matr(this->size);
  for (int i = 0; i < this->size; i++)
  {
    matr[i][0] = 1;
    T temp = copyA[i][0];
    for (int j = 0; j < (this->size - i); j++)
    {
      copyA[i][j] = copyA[i][j] / temp;
      matr[i][j] = matr[i][j] / temp;
    }
  }
  for (int j = 1; j < this->size; j++)
  {
    for (int i = 0; i < j; i++)
    {
      T temp = copyA[i][j - i];
      for (int k = j - i, a = 0; k < (this->size - i); k++)
        {
	  copyA[i][k] = copyA[i][k] - copyA[j][a] * temp;
	  matr[i][k] = matr[i][k] - matr[j][a++] * temp;
	}
     }
  }
  return ((*this) * matr);
}


template <class FriendT>  
istream& operator>>(istream &istr, TMatrix<FriendT> &A)
{
  for (int i = 0; i < A.size; i++)
    istr >> A.vector[i];
  return istr;
}

template <class FriendT>
ostream & operator<<(ostream &ostr, const TMatrix<FriendT> &A)
{
  for (int i = 0; i < A.size; i++)
  {
    for (int j = 0; j < i; j++)
      ostr << "\t";
    ostr << A.vector[i] << endl;
   }
   return ostr;
}
