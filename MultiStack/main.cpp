#include "MultiStack.h"
#include "..//Exception/Exception.h"
#include <iostream>

using namespace std;

int main()
{
	TMStack <int> MStack(5, 15);
	MStack.Set(1, 1);
	MStack.Set(1, 2);
	MStack.Set(1, 3);
	MStack.Set(1, 4);
	cout << endl;
	cout << MStack.Get(1);
	cout << endl;
        cout << MStack.Get(1);
	cout << endl;
        cout << MStack.Get(1);
	cout << endl;
	return 0;
}
