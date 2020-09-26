#include "../../std_lib_facilities.h"

int area(int length, int width){

	return length * width;
}

constexpr int frame_width = 2;

int framed_area(int x, int y){

	return area(x - frame_width, y - frame_width);
}

int main(){

	int x = -1;
	int y = 2;
	int z = 4;

	if (x<=0) error("non-positive x");
	if (y<=0) error("non-positive y");
	int area1 = area(x, y);
	cout << "area1: " << area1 << endl;

	//if (1 - 2 <= 0 || z - 2 <= 0)
	if (1 - frame_width <= 0 || z - frame_width <= 0)
		error("non-positive argument for area() called by framed_area()");
	int area2 = framed_area(1, z);
	cout << "area2: " << area2 << endl;

	if (y - frame_width <= 0 || z - frame_width <= 0)
		error("non-positive argument for area() called by framed_area()");
	int area3 = framed_area(y, z);
	cout << "area3: " << area3 << endl;

	double ratio = double(area1)/area3;
	cout << "ratio: " << ratio << endl;
	
	return 0;
}