#include <iostream>
#include "..//ArrayListLib/ArrayList.h"

int main()
{
	TArrayList <int> L(1);
	L.PutBegin(1);
	std::cout << L.GetBegin();
	std::cout << "\n";
	return 0;
}