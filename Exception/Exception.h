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
  void Print()
  {
  cout << "\nWarning! \nMessage: " << message << endl;
  }
};

TException::TException(string _message) : message(_message) {}

