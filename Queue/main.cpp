#include <iostream>
#include "../QueueLib/Queue.h"
#include "Exception.h"
using namespace std;

int main()
{ 
  try
  {
    int n;
    cout << "Enter the number of elements in the queue\n";
    cin >> n;
    TQueue<int> queue(n);
    int elem;
    cout << "Enter the elements of the queue\n";
    for (int i = 0; i < n; i++)
    {
      cin >> elem;
      queue.Put(elem);
    }
    queue.PrintQueue();
    cout << "\nCopy the queue\n";
    TQueue <int> queue1(queue);
    queue1.PrintQueue();
    cout << "\nGet the element\n";
    queue.Get();
    queue.PrintQueue();
  }
  catch (TException exception)
  {
    exception.Print();
  }
	return 0;  
}
