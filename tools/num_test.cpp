#include <iostream>
#include <limits>
using namespace std;

int main(){
    int max_int = numeric_limits<int>::max();
    int min_int = numeric_limits<int>::min();
    double max_double = numeric_limits<double>::max();
    double min_double = numeric_limits<double>::min();
    cout << "max_int = " << max_int << endl;
    cout << "min_int = " << min_int << endl;
    cout << "max_double = " << max_double << endl;
    cout << "min_double = " << min_double << endl;
}
