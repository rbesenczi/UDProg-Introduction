#include "../../std_lib_facilities.h"

int area(int length, int width){

	if (length <= 0 || width <= 0)
		return -1;

	return length * width;
}

int framed_area(int x, int y){

	constexpr int frame_width = 2;

	//Nem szerencsés még mindig!
	//if (x - frame_width <= 0 || y - frame_width <= 0)
	//	error("non-positive argument for area() called by framed_area()");

	return area(x - frame_width, y - frame_width);
}

int main(){

	int x = -1;
	int y = 2;
	int z = 4;

	int area1 = area(x, y);
	if (area1 < 0) error ("non-positive area\n");
	cout << "area1: " << area1 << endl;

	int area2 = framed_area(1, z);
	cout << "area2: " << area2 << endl;

	int area3 = framed_area(y, z);
	cout << "area3: " << area3 << endl;

	double ratio = double(area1)/area3;
	cout << "ratio: " << ratio << endl;
	
	return 0;
}