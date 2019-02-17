#pragma once
#include "Polynomial.h"

int main()
{

	int mas[] = { 1,2,3 };
        int nmas[] = { 7,3,4};

	TMonom M1(3, mas, 2),  M2(3, nmas, 1);

	cout << "\tMonomial 1: " << M1 << "\n";
	cout << "\tMonomial 2: " << M2 << "\n";

	TPolynom P(3);
	P += M1;
	P += M2;
	cout << "\n\tPolynomial = M1 + M2 = " << P << "\n";
	return 0;
}
