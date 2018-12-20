#include <iostream>
#include "../VectorLib/VectorLib.h"
#include <locale.h>
using namespace std;
int main()
{   
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер вектора\n";
	cin >> n;
	TVector<int> vector1(n);
	cout << "Введите элементы вектора\n";
	cin >> vector1;
	cout << "\nВывод элементов вектора\n";
	cout << vector1 << "\n"; 
	TVector<int> vector2(n), res(n);
	cout << "Введите элементы второго вектора\n";
	cin >> vector2;
	cout << "\nВывод элементов второго вектора\n";
	cout << vector2 << "\n";
	cout << "\nРазность второго и первого векторов\n";
	res = vector2 - vector1;
	cout << res << endl;
	cout << "\nСумма первого и второго векторов\n";
	res = vector1 + vector2;
	cout << res << endl;
	return 0;
}
