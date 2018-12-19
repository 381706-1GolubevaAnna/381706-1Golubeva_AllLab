
#include <iostream>
#include "../QueueLib/Queue.h"

using namespace std;

int main()
{   
	try
  {
	TQueue<int> queue(5);
	queue.Put(1);
	queue.Put(2);
	queue.Put(3);
	int temp;
	temp = queue.Get();
	cout << temp <<endl;
	TQueue <int> queue1(queue);
  catch (TException exception)
  {
    exception.Print();
  }
	return 0;  
}
