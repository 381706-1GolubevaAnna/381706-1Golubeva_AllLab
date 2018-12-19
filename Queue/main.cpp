#include <iostream>
#include "../QueueLib/Queue.h"
#include "Exception.h"
#include <locale.h>
using namespace std;

int main()
{ 
  setlocale(LC_ALL, "Russian");
	try
	{
	int n;
	cout << "Введите количество элементов в очереди\n"
	cin >> n;
	TQueue<int> queue(n);
	int elem;
	cout << "Введите элементы очереди\n";
	for (int i = 0; i < n; i++)
	{
		cin >> elem;
		queue.Put(elem);
	}
	cout << "\nВывод очереди на экран\n";
	queue.PrintQueue();
	cout << "\Скопировать очередь\n";
	TQueue <int> queue1(queue);
	queue1.PrintQueue();
	cout << "\nЗабрать элемент из очереди\n";
	queue.Get();
	cout << "\nВывод очереди на экран\n";
	queue.PrintQueue();
	}
  catch (TException exception)
  {
    exception.Print();
  }
	return 0;  
}
