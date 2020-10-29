#include "std_lib_facilities.h"

int main() 
{

	cout << "Please enter an expression (+,-,*,/)\n";
	cout << "Please enter an x to the end of expression\n";

	int lval = 0, rval = 0;

	cin >> lval;
	if (!cin) error("No lval");

	for(char op; cin >> op; ){

		if(op != 'x') cin >> rval;
		if(!cin) error ("No rval");

		switch(op){
			case '+':
				lval += rval;
				break;
			case '-':
				lval -= rval;
				break;
			case '*':
				lval *= rval;
				break;
			case '/':
				lval /= rval;
				break;
			default:
				cout << "Result: " << lval << endl;
				return 0;
		}
	}

	error("bad expression");

	return 0;
}