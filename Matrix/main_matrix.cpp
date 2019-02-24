#include <iostream>
#include "../MatrixLib/MatrixLib.h"
using namespace std;   
int main()
{
  try
  {
    TMatrix<int> A(5), B(2), res(2);
    A[0][0] = 7;
    A[0][1] = 2;
    A[1][0] = 3;
   
    B[0][0] = 4;
    B[0][1] = 3;
    B[1][0] = 2;
 
   
    res = A + B;
    cout << "A + B" << endl << res << endl;

    res = A - B;
    cout << "A - B" << endl << res << endl;

    res = A * B;
    cout << "A * B" << endl << res << endl;

    res = A / B;
    cout << "A / B" << endl << res << endl;
  }
 catch (TException exception)
  {
    exception.Print();
  }

  return 0;
}
