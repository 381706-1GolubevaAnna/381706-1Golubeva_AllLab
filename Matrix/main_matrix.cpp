#include <iostream>
#include "../MatrixLib/MatrixLib.h"
using namespace std;   
int main()
{
  try
  {
    TMatrix<int> A(4), B(2), res(2);
    /*A[0][0] = 7;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 6;
	  */
    B[0][0] = 4;
    B[0][1] = 3;
    B[1][0] = 5;
    B[1][1] = 3;  
 
      for (int i = 0; i < 5; i++)
	for (int j = 0; j < 5 - i; j++) 
	{
	  A[i][j] = (i + 1) * (j + 1);
	 
	}
    cout << "A\n";
    cout << A << endl;
    cout << "B";
    cout << B << endl;
  /*
    res = A + B;
    cout << "A + B" << endl << res << endl;

    res = A - B;
    cout << "A - B" << endl << res << endl;

    res = A * B;
    cout << "A * B" << endl << res << endl;

    res = A / B;
    cout << "A / B" << endl << res << endl;
  }
*/
 catch (TException exception)
  {
    exception.Print();
  }

  return 0;
}
