#include <iostream>
#include "Polish.h"

using namespace std;

int main()
{
	
	{
		char a[] = "(-1*7+9/3)";
		TString example(a);
		TQueue<char> B;
		cout << "\t" << example << "\n\n";
		B = ConvertToPolish(example);

		cout << "\t"; B.PrintQueue();
		cout << " = " << Res(B) << "\n";

	}

	

	return 0;
}