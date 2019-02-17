#pragma once
#include <iostream>
#include <string>

class TException
{
  private:
  string message;
  public:
  TException(string _message) message(_message) {}
  void Print()
  {
  cout << "\nWarning! \nMessage: " << message << endl;
  }
};


