#include "Triangular_iterator.cpp"
#include "Triangular.h"
#include <iostream>

using namespace std;

int sum( const Triangular &trian );

int main(){

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

    Triangular tri4(20);
    Triangular_iterator it = tri4.begin();
    Triangular_iterator end_it = tri4.end();
    
    cout << "Triangular series of " << tri4.length() << " elements\n"; 
    while( it!=end_it){
        cout <<*it<< " ";
	++it;
    }
    cout << endl;
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
