#include "../../std_lib_facilities.h"
 
int main() 
{
    cout << "type\tlowest()\tmin()\t\tmax()\n\n"
              << "bool\t"
              << numeric_limits<bool>::lowest() << "\t\t"
              << numeric_limits<bool>::min() << "\t\t"
              << numeric_limits<bool>::max() << '\n'
              << "uchar\t"
              << +numeric_limits<unsigned char>::lowest() << "\t\t"
              << +numeric_limits<unsigned char>::min() << "\t\t"
              << +numeric_limits<unsigned char>::max() << '\n'
              << "int\t"
              << numeric_limits<int>::lowest() << '\t'
              << numeric_limits<int>::min() << '\t'
              << numeric_limits<int>::max() << '\n'
              << "float\t"
              << numeric_limits<float>::lowest() << '\t'
              << numeric_limits<float>::min() << '\t'
              << numeric_limits<float>::max() << '\n'
              << "double\t"
              << numeric_limits<double>::lowest() << '\t'
              << numeric_limits<double>::min() << '\t'
              << numeric_limits<double>::max() << '\n';
}