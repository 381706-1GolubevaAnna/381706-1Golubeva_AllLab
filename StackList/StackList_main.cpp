#include <iostream>
#include "../StackListLib/StackList.h"

using namespace std;

int main()
{
  cout <<  "\nEnter stack size: ";
	int size,temp;
	cin >> size;
		TStackList<int> St(size);
		cout << "Enter the elements: ";
		for (int i = 1; i <= size; i++)
		{
			cin >> temp;
			St.Put(temp);
		}
		cout << "\nStack :\n";
		St.Print();
		cout << endl;
		cout << "\nGet element of the Stack: ";
		cout << St.Get();
		cout << endl;
  return 0;
}
