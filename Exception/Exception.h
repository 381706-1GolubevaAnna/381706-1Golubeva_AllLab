#pragma once
#include <iostream>
#include <string>

class TException
{
  private:
  std::string message;
  public:
  TException(std::string _message) message(_message) {}
  void Print()
  {
  std::cout << "\nWarning! \nMessage: " << message << std::endl;
  }
};


