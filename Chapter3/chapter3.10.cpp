#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
/*
    ifstream in_file(cin);
    ofstream out_file(cout);

    if( !in_file || !out_file ){
        cerr << "!! unable to open the necessary files.\n";
	return -1;
    }
*/
    istream_iterator<string> is(cin);
    istream_iterator<string> eof;

    vector<string> text;
    copy(is,eof,back_inserter(text) );

    sort(text.begin(),text.end());

    ostream_iterator<string> os( cout," " );
    copy(text.begin(),text.end(),os);
}
