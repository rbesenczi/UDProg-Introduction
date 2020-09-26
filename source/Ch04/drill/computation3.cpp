#include "../../std_lib_facilities.h"

int main()
{
	double a = 0.0;
	double max = 0, min = 0;

	while (cin >> a)
	{
		cout << "a=" << a << endl;

		if (a < min)
		{
			cout << "Smallest so far.\n";
			min = a;
		}

		if (a > max)
		{
			cout << "Largest so far.\n";
			max = a;
		}
	}
	
	return 0;
}
