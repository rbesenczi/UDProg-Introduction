#include "std_lib_facilities.h"

int main() 
{

	cout << "Please enter an expression\n";

	int lval = 0, rval = 0;
	char op = 0;

	int res;

	cin >> lval >> op >> rval;

	if (op == '+')
		res = lval + rval;
	else if (op == '-')
		res = lval - rval;

	cout << "Result: " << res << endl;

	return 0;
}