#include <iostream>
#include "../MatrixLib/MatrixLib.h"
#include <time.h>
#include <locale.h>
using namespace std;
int main()
{   
	setlocale(LC_ALL, "Russian");
	cout << "������� ������ �������\n";
	int n;
	cin >> n;
	TMatrix<int> _matrix(n);
	cout << "������� �������� �������\n";
	cin >> _matrix;
	cout << "\n����� �������\n";
	cout << _matrix <<endl; 
	return 0;  
}