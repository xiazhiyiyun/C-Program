#include "triangular.h"
#include <iostream>

using namespace std;

int main(){
    char ch;
    int vl;
    bool more = true;

    while(more){
        cout << "Enter value : ";
	cin >> vl;
	bool is_elem = Triangular::is_elem(vl);
	cout << vl
	     << (is_elem ? " is" : " isn't")
	     << " the element of Triangular sequence.\n"
	     << "Another value? y/n:  ";
  	cin >> ch;
	if(ch == 'n' || ch == 'N')
	    more = false;
    }
}
