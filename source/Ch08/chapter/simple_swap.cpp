#include "../../std_lib_facilities.h"

void swap (double& d1, double& d2)
{
	double temp = d1;
	d1 = d2;
	d2 = temp;
}

int main()
{
	double x = 1.23;
	double y = 2.12;
	cout << "x=" << x << " y=" << y << endl;	
	swap(x, y);
	cout << "x=" << x << " y=" << y << endl;

	return 0;

}