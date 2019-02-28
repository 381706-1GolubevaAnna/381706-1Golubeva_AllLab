#include <iostream>
#include "../MatrixLib/MatrixLib.h"
using namespace std;   
int main()
{
  try
  {
    TMatrix<int> A(5), B(5), res(5);
  
    for (i = 0; i < 5; i++)
	  for (j = 0; j < 5 - i; j++) 
	  {
	  A[i][j] = i * (j + 1);
	  B[i][j] = i * 5 + j * 4;
	
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
