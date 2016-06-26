#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

typedef vector<string> vstring;

int main(){
    ifstream ifile("exercise3.3.in");
    ifstream ofile("exercise3.3.out");

    if( !ifile || !ofile ){
        cerr << "Unable to open file -- bailling out"
    }

}
