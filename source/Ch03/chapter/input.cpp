#include "../../std_lib_facilities.h"

int main(){

	cout << "Please enter your first and second name and age (followed by 'enter'):\n";
	
	string first_name, second_name;
	int age;
	cin >> first_name >> second_name >> age;
	
	second_name += " Jr.";
	
	++age;
	
	string name = first_name + ' ' + second_name;
	
	cout << "Hello, " << name << " (age " << age << ")!\n";

	return 0;
}