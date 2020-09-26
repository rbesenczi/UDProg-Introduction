#include "../../std_lib_facilities.h"

int main(){

	vector<int> v = {5, 7, 9, 4, 6, 8};
	vector<string> philosphers = {"Kant", "Plato", "Hume", "Kierkegaard"};

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;

	for (auto name : philosphers)
		cout << name << endl;

	vector<double> dv;

	cout << "dv size: " << dv.size() << endl;

	dv.push_back(2.7);
	dv.push_back(5.6);
	dv.push_back(7.9);

	cout << "dv size: " << dv.size() << endl;

	for (auto number : dv)
		cout << number << endl;

	return 0;
}