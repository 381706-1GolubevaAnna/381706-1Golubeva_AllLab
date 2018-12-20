#pragma once

#include <iostream>
#include "../VectorLib/VectorLib.h"

using namespace std;

template <class T>
class TMatrix :public TVector<TVector<T>> 
{
public:
	TMatrix(int n = 10);
	TMatrix(const TMatrix<T> &A);
	TMatrix(const TVector<TVector<T>> &A);
	TMatrix<T>& operator=(TVector<TVector<T>> &A);
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
TMatrix<T> ::TMatrix(int n) : TVector<TVector<T>>(n)
{
		if (n < 0||n>10000)  
			throw TException("Error. Negative or too large size of matrix.");*/
		else
		{
			for (int i = 0; i < n; i++)
				this->vector[i] = TVector <T>(n - i);
		}
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &A) :TVector<TVector<T>>(A) {}

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T>> &A) : TVector<TVector<T>>(A) {}

template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &A)
{
	return TVector<TVector<T>>::operator==(A);
}

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &A)
{
	return TVector<TVector<T>>::operator!=(A);
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(TVector<TVector<T>> &A)
{
	TVector<TVector<T>>::operator=(A);
	return *this;
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(TMatrix<T> &A)
{
	if (this->size!= A.size)
		throw TException("Error. Different dimensions.");
	else
		return TVector<TVector<T>> :: operator+(A);
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(TMatrix<T> &A)
{
	if (this->size!= A.size)
		throw TException("Error. Different dimensions.");
	else
		return TVector<TVector<T>> :: operator-(A);
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
/*
template <class T>
TMatrix<T> TMatrix<T>::operator/(TMatrix<T> &A)
{
	if (this->size!= A.size)
		throw TException("Error. Different dimentions");
	
	int N = (*this).size;
	double detChecking = 1;

	for (int i = 0; i < N; i++)
		detChecking *= (*this).vector[i][0];

	if (detChecking < 0.000001)
		throw TException("Error. Cannot work with matrixes that have det = 0");

	TMatrix <T> replicaMatr(A);
	TMatrix <T> middleStepMatr(N);

	for (int row = 0; row < N; row++)
	{
		middleStepMatr[row][0] = 1;
		T k = replicaMatr[row][0];
		for (int col = 0; col < N - row; col++)
		{
			replicaMatr[row][col] = replicaMatr[row][col] / k;
			middleStepMatr[row][col] = middleStepMatr[row][col] / k;
		}
	}

	for (int col = 1; col < N; col++)
	{
		for (int row = 0; row < col; row++)
		{
			T temp = replicaMatr[row][col - row];
			for (int k = col - row, c = 0; k < N - row; k++)
			{
				replicaMatr[row][k] = replicaMatr[row][k] - replicaMatr[col][c] * temp;
				middleStepMatr[row][k] = middleStepMatr[row][k] - middleStepMatr[col][c++] * temp;
			}
		}
	}
	return ((*this) * middleStepMatr);
}
*/

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
