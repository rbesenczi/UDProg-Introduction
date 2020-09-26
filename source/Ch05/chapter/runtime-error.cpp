#include "../../std_lib_facilities.h"

int area(int length, int width){

	return length * width;
}

int framed_area(int x, int y){

	return area(x-2,y-2);
}

int main(){

	int x = -1;
	int y = 2;
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
}