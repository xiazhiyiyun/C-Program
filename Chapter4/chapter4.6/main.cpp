#include "Triangular.h"
#include <iostream>

using namespace std;

int sum( const Triangular &trian );

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

    Triangular tri(4);
//    cout << tri << " -- sum of elements: "
         cout<< sum( tri ) << endl;

    Triangular tri1(4,3);
//    cout << tri1 << " -- sum of elements: "
         cout<< sum( tri1 ) << endl;

    Triangular tri2(4,8);
  //  cout << tri2 << " -- sum of elements: "
         cout<< sum( tri2 ) << endl;
    Triangular tri3 = tri1;
    cout << sum(tri3) << endl;

}

int sum( const Triangular &trian ){
    if( !trian.length() )
        return 0;
    int val = 0;
    int sum = 0;
    trian.next_reset();

    while( trian.next(val) ){
        cout << "val = " << val << endl;
        sum += val;
    }

    return sum;
}
