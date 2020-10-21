#include "../../std_lib_facilities.h"

int main()
{
	vector<int> v {1,2,3,4,5,6,7,8,9,10};

	for (const auto& e : v)
		cout << e << endl;

	for (auto& e : v)
		cout << e << endl;

	for (auto e : v)
		cout << e << endl;

	return 0;
}
