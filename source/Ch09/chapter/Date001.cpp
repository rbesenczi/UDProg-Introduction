#include "../../std_lib_facilities.h"

struct Date {
	int y, m, d;
};

void init_date(Date& date, int y, int m, int d)
{
	if (y > 0)
		date.y = y;
	else
		error("Invalid year");
	if (m < 12 && m > 0)
		date.m = m;
	else
		error("Invalid month");
	if (d > 0 && d < 32)
		date.d = d;
	else
		error("Invalid day");
}

void add_day(Date& date, int n)
{
	date.d += n;
	if (date.d > 31) 
	{
		date.m++;
		date.d -= 31;
		if (date.m > 12)
		{
			date.y++;
			date.m -= 12;
		}
	}
}

int main()
{
	Date today;

	today.y = 2020;
	today.m = 9;
	today.d = 1;

	cout << "Date: " << today.y << ". " << today.m << ". " << today.d << ".\n";

	today.y = -3;
	today.m = 92;
	today.d = 100;

	cout << "Date: " << today.y << ". " << today.m << ". " << today.d << ".\n";

	today.y = 2019;
	today.m = 2;
	today.d = 29;

	cout << "Date: " << today.y << ". " << today.m << ". " << today.d << ".\n";

	Date today2;
	init_date(today2, 2020, 8, 31);

	cout << "Date: " << today2.y << ". " << today2.m << ". " << today2.d << ".\n";

	add_day(today2, 1);

	cout << "Date: " << today2.y << ". " << today2.m << ". " << today2.d << ".\n";


	return 0;
}