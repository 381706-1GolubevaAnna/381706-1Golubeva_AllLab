#pragma once
#include "Exception.h"

class TMonom
{
protected:
	TMonom* next;  //указатель на следующий моном
	int *power;    //массив степеней
	int n;         //кол-во переменных в мономе
	double coeff;  //коэффицтент
public:
	TMonom();
	TMonom(int _n, int* _power, double _coeff);
	TMonom(TMonom& A);
	virtual ~TMonom();

	void SetPower(int* _power);
	void SetNext(TMonom* _next);
	void SetCoeff(double _coeff);
	void SetN(int _n);
	int* GetPower();
	TMonom* GetNext();
	double GetCoeff();
	int GetN();

	TMonom& operator=(TMonom& A);
	TMonom operator+(TMonom& A);
	TMonom operator+=(TMonom& A);
	TMonom operator-(TMonom& A);
	TMonom operator-=(TMonom& A);
	TMonom operator*(TMonom& A);
	TMonom operator*=(TMonom& A);
	bool operator==(TMonom& A);
	bool operator>(TMonom& A);
	bool operator<(TMonom& A);

	friend istream& operator>>(istream& istr, TMonom& A);
	friend ostream& operator<<(ostream& ostr, TMonom& A);
};

//istream& operator>>(istream& istr, TMonom& A)
//{
//	istr >> A.coeff;
//	for (int i = 0; i < A.n; i++)
//		istr >> A.power[i];
//	return istr;
//}
//
//ostream& operator<<(ostream& ostr, TMonom& A)
//{
//	ostr << A.coeff;
//	if (A.coeff != 0)
//	{
//		for (int i = 0; i < A.n; i++)
//			if (A.power[i] != 0)
//			{
//				ostr << "(x" << i << "^" << M.power[i] << ")";
//			}
//	}
//	return ostr;
//}