#include "../../std_lib_facilities.h"

class Bad_area { };

int area(int length, int width){

	if (length <= 0 || width <= 0) throw Bad_area{};
	return length * width;
}

int framed_area(int x, int y){

	constexpr int frame_width = 2;

	return area(x - frame_width, y - frame_width);
}

int main()
try {

	int x = 1;
	int y = -2;
	int z = 4;

	int area1 = area(x, y);
	cout << "area1: " << area1 << endl;

	int area2 = framed_area(1, z);
	cout << "area2: " << area2 << endl;

	int area3 = framed_area(y, z);
	cout << "area3: " << area3 << endl;

	double ratio = double(area1)/area3;
	cout << "ratio: " << ratio << endl;
	
	return 0;
	
} catch (Bad_area) {
	cout << "Bad arguments to area()\n";
}