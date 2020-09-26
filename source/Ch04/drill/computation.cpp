#include "../../std_lib_facilities.h"

int main()
{
	int a = 0, b = 0;
	
	while (cin >> a >> b)
	{
		cout << "a=" << a << " b=" << b << endl;

		if (a == b) cout << "a and b are equal.\n";
		if (a < b) cout << "max(" << a << "," << b << ") is " << b << '\n';
		if (a > b) cout << "max(" << a << "," << b << ") is " << a << '\n';
	}

	return 0;
}