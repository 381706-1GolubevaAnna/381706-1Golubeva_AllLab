
#include <iostream>
#include "../QueueLib/Queue.h"

using namespace std;

int main()
{   
	TQueue<int> queue(5);
	queue.Put(1);
	queue.Put(2);
	queue.Put(3);
	int temp;
	temp = queue.Get();
	cout << temp <<endl;
	return 0;  
}