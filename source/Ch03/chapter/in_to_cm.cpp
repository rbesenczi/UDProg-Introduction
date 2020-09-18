#include "../../std_lib_facilities.h"

int main(){

	const double cm_per_inch = 2.54;
	
	double length = 1;
	while (length != 0)
	{
		cout << "Please enter a value in inches: ";
		cin >> length;
		cout << length << " in = " << cm_per_inch * length << " cm\n";
	}

	return 0;
}
