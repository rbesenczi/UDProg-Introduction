#include "../../std_lib_facilities.h"

int main(){

	char c1 = 'x';
	int i1 = c1;
	int i2 = 'x';

	char c2 = i1;

	cout << c1 << ' ' << i1 << ' ' << i2 << ' ' << c2 << '\n';

	double d1 = 2.3;
	double d2 = d1 + 2;

	cout << d2 << '\n';

	return 0;
}
