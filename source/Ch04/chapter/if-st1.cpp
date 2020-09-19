#include "../../std_lib_facilities.h"

int main()
{
	int a = 0, b = 0;
	
	cout << "Please enter 2 integer values!\n";
	cin >> a >> b;

	if (a < b)
		cout << "max(" << a << "," << b << ") is " << b << '\n';
	else
		cout << "max(" << a << "," << b << ") is " << a << '\n';

	return 0;
}