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
    cout << "Введите количество элементов в стеке\n";
    cin >> n;
    TStack<int> stack(n);
    int elem;
    cout << "Введите элементы стека\n";
    for (int i = 0; i < n; i++)
    {
      cin >> elem;
      stack.Put(elem);
    }
    cout << "\nВывод стека на экран\n";
    stack.PrintStack();
    cout << "\nЗабрать элемент из стека\n";
    stack.Get();
    cout << "\nВывод стека на экран\n";
    stack.PrintStack();
    cout << "\nСкопировать стек\n";
    TStack<int> newStack(stack);
    newStack.PrintStack();
  }
  catch (TException exception)
  {
    exception.Print();
  }
  return 0;
}
