#include "../../std_lib_facilities.h"

int error_ID_number = 0;

int area(int length, int width){

	if (length <= 0)
		error_ID_number = 2;

	if (width <= 0)
		error_ID_number = 3;
		
	return length * width;
}

int framed_area(int x, int y){

	constexpr int frame_width = 2;

	return area(x - frame_width, y - frame_width);
}

int main(){

	int x = 1;
	int y = -2;
	int z = 4;

	int area1 = area(x, y);
	if (error_ID_number == 2) error ("non-positive length\n");
	if (error_ID_number == 3) error ("non-positive width\n");
	cout << "area1: " << area1 << endl;

	int area2 = framed_area(1, z);
	cout << "area2: " << area2 << endl;

	int area3 = framed_area(y, z);
	cout << "area3: " << area3 << endl;

	double ratio = double(area1)/area3;
	cout << "ratio: " << ratio << endl;
	
	return 0;
}