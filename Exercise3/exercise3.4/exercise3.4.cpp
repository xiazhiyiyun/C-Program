#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class even_elem {
public:
    bool operator() (int elem ){
        return elem % 2 ? false : true;
    }

};

int main(){
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;

    vector<int> number;

    copy(is,eof,back_inserter(number));

    vector<int>::iterator division = partition(number.begin(),number.end(),even_elem());

    ofstream even_file("even_file");
    ofstream odd_file("odd_file");

    if(!even_file || !odd_file){
        
	cerr << "\nUnable to open the output files! -- bailling out ! " << endl;
	return -1;
    }

    ostream_iterator<int> even_iter( even_file,"\n" ),odd_iter ( odd_file," " );

    copy(number.begin(), division, even_iter);
    copy(division, number.end(), odd_iter);
}
