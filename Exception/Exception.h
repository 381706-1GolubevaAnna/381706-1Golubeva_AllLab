#pragma once

#include <iostream>
#include <string>
using namespace std;

class TException
{
private:
	string message;
public:
	TException(string _message);
	void Print();
};

TException::TException(string _message) : message(_message) {}

void TException::Print()
{
	cout << "\nWarning! \nMessage: " << message << endl;
}