#include <iostream>
#include "../StackLib/Stack.h"
#include "../Exception/Exception.h"
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		int n;
		cout << "������� ���������� ��������� � �����\n";
		do
			cin >> n;
		while (n < 0);
		TStack<int> stack(n);
		int elem;
		cout << "������� �������� �����\n";
		for (int i = 0; i < n; i++)
		{
			cin >> elem;
			stack.Put(elem);
		}
		cout << "\n������ ����� �� �����\n";
		stack.PrintStack();
		cout << "\n������� ������� �� �����\n";
		stack.Get();
		cout << "\n������ ����� �� �����\n";
		stack.PrintStack();
		cout << "\n�������� ����\n";
		TStack<int> newStack(stack);
		newStack.PrintStack();
	}
	catch (TException exception)
	{
		exception.Print();
	}

	return 0;
}