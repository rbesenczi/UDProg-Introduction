#include "../../std_lib_facilities.h"

int main(){

	int a = 20000;
	char c = a; 
	//char c {a}; // warning: narrowing conversion of ‘a’ from ‘int’ to ‘char’ inside { }
	int b = c;
	if (a != b)
		cout << "a!=b, a=" << a << " b=" << b << '\n';
	else
		cout << "Hatalmas karakterünk van!\n";

	return 0;
}
