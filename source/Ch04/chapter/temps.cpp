#include "../../std_lib_facilities.h"

int main(){

	vector<double> temps;
	for (double temp; cin >> temp; )
		temps.push_back(temp);

	for (auto temp : temps)
		cout << temp << endl;

	double sum = 0;
	for (auto temp : temps) sum += temp;

	cout << "Average temperature: " << sum/temps.size() << endl;

	sort(temps);
	cout << "Median temperature: " << temps[temps.size()/2] << endl;

	return 0;
}