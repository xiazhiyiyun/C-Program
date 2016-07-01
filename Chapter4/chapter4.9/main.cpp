#include "LessThan.cpp"
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int count_less_than( const vector<int> &vec, int comp );
void print_less_than( const vector<int> &vec,int comp ,ostream &os = cout);

int main(){
    
    LessThan le(16);
    int arr[16] = {17,12,44,9,18,45,6,14,23,67,9,0,27,55,8,16}; 
    vector<int> ivec(arr,arr+16);
    int comp = 20;

    ofstream os("debug.txt");
    os << "Number of less than " << comp << " is "
         << count_less_than(ivec,comp) <<" .\n";

    print_less_than(ivec,comp,os);
}

int count_less_than( const vector<int> &vec, int comp ){
    LessThan lt(comp);
    int count = 0;
    
    for(int ix = 0;ix < vec.size();ix++){
        if( lt( vec[ix]) )
	    count++;
    }

    return count;
}

void print_less_than( const vector<int> &vec,int comp ,ostream &os){

    LessThan lt(comp);

    vector<int>::const_iterator it = vec.begin();
    vector<int>::const_iterator end_it = vec.end();

    os << "elements less than " << lt.cam_val() << endl;

    while( ( it = find_if( it,end_it,lt ) ) != end_it ){
        os << *it << ' ';
	++it;
    }

    os << endl;
}
