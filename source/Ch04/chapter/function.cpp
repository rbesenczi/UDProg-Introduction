#include "../../std_lib_facilities.h"

int square(int x)
{
	return x*x;
}

int main()
{
	for(int i = 0; i < 100; ++i)
		cout << i << '\t' << square(i) << '\n';

	return 0;
}