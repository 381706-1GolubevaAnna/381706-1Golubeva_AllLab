#pragma once
#include "Monomial.h"
#include <iostream>
using namespace std;
class TPolynom
{
protected:
	TMonom *start;
	int n;          //количество переменных в мономе
	int size;       //количество мономов 
public:
	TPolynom(int _n = 10);
	TPolynom(TPolynom & P);
	~TPolynom();
	int GetSize();
	int GetN();
	TMonom* GetStart();
	TPolynom operator+(TPolynom &P);
	TPolynom operator-(TPolynom &P);
	TPolynom operator*(TPolynom &P);
	TPolynom& operator=(TPolynom &P);
	TPolynom& operator+=(TMonom &M);
	TPolynom& operator-=(TMonom &M);
	bool operator==(const TPolynom &P);
	friend std::ostream& operator<<(std::ostream& ostr, TPolynom& P);
};

