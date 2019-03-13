#include "List.h"

int main()
{
		TList<int> L;
		int n1, n2, temp;
		cout << "Put the elements in the beginning. Enter the number of elements: ";
		cin >> n1;
		cout << "Enter the elements: ";
		for (int i = 1; i <= n1; i++)
		{
			cin >> temp;
			L.PutBegin(temp);
		}
		cout << "\nList: ";
		L.Print();
		cout << "\n Put the elements in the end. Enter the number of elements:";
		cin >> n2;
		cout << "Enter the elements: ";
		for (int i = 1; i <= n2; i++)
		{
			cin >> temp;
			L.PutEnd(temp);
		}
		cout << "\nList\n";
		L.Print();
		cout << "\nGet the element from the beginning of the List: ";
		cout << L.GetBegin();
		cout << "\nGet the element from the end of the List: ";
		cout<< L.GetEnd();
		cout << "\nList:\n";
		L.Print(); 
		cout << endl;

}
