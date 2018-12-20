#include <iostream>
#include "../MatrixLib/MatrixLib.h"
#include <time.h>
#include <locale.h>
using namespace std;
int main()
{   
	setlocale(LC_ALL, "Russian");
	cout << "Введите размер матрицы\n";
	int n;
	cin >> n;
	TMatrix<int> _matrix(n);
	cout << "Введите элементы матрицы\n";
	cin >> _matrix;
	cout << "\nВывод матрицы\n";
	cout << _matrix <<endl; 
	return 0;  
}