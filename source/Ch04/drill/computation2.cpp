#include "../../std_lib_facilities.h"

int main()
{
	double a = 0.0, b = 0.0;

	while (cin >> a >> b)
	{
		cout << "a=" << a << " b=" << b << endl;

		if (a == b) cout << "a and b are equal.\n";
		if (a < b) cout << "max(" << a << "," << b << ") is " << b << '\n';
		if (a > b) cout << "max(" << a << "," << b << ") is " << a << '\n';
		
		if (abs(a - b) <= 0.01) cout << "a and b are almost equal.\n";
	}

	return 0;
}