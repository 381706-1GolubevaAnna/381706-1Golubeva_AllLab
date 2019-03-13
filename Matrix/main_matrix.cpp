#include <iostream>
#include "../MatrixLib/MatrixLib.h"
using namespace std;   
int main()
{
  try
  {
    TMatrix<int> A(2), B(2), res(2);
    for (int i = 0; i < 2; i++)
	  for (int j = 0; j < 2 - i; j++) 
	  {
	  A[i][j] = 1;
	  B[i][j] = 4;

	  }

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
