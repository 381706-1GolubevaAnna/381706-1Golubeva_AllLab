#include "MultiStack.h"
#include "..//Exception/Exception.h"
#include <iostream>

using namespace std;

int main()
{
	
	TMStack <int> MStack(3, 12);
	MStack.Set(2, 1);
	MStack.Set(2, 2);
	MStack.Set(2, 3);
	cout << MStack.Get(2);
	cout << endl;
    cout << MStack.Get(2);
	return 0;
}