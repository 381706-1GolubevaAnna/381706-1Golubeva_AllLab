#include <iostream>
#include "Stack.h"
#include "Exception.h"
#include <locale.h>
using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");
  try
  {
    int n;
    cout << "Enter the number of elements in the stack\n";
    cin >> n;
    TStack<int> stack(n);
    int elem;
    cout << "Enter the elements of the stack\n";
    for (int i = 0; i < n; i++)
    {
      cin >> elem;
      stack.Put(elem);
    }
    cout <<endl;
    stack.PrintStack();
    cout << "\nGet the element of the stack\n";
    stack.Get();
    cout <<endl;
    stack.PrintStack();
    cout << "\nCopy stack\n";
    TStack<int> newStack(stack);
    newStack.PrintStack();
  }
  catch (TException exception)
  {
    exception.Print();
  }
  return 0;
}
