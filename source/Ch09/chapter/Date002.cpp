#include "../../std_lib_facilities.h"

struct Date {
	int year, month, day;
	Date(int y, int m, int d);
	void add_day(int n);
};

Date::Date(int y, int m, int d)
{
	if (y > 0)
		year = y;
	else
		error("Invalid year");
	if (m < 13 && m > 0)
		month = m;
	else
		error("Invalid month");
	if (d > 0 && d < 32)
		day = d;
	else
		error("Invalid day");
}

void Date::add_day(int n)
{
	day += n;
	if (day > 31) 
	{
		month++;
		day -= 31;
		if (month > 12)
		{
			year++;
			month -= 12;
		}
	}
}

int main()
try {
	Date today {2020, 8, 31};

	//Date some_day {12, 24, 2018}; //Runtime error
	//Date my_birthday;

	Date my_birthday {2020,12,31};

	cout << "Date: " << today.year << ". " << today.month << ". " << today.day << ".\n";

	today.add_day(1);

	cout << "Date: " << today.year << ". " << today.month << ". " << today.day << ".\n";

	my_birthday.day++;

	cout << "Date: " << my_birthday.year << ". " << my_birthday.month << ". " << my_birthday.day << ".\n";
	
	return 0;

} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
}