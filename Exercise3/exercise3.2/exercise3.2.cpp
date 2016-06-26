#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <functional>

using namespace std;

class LessThan {
    public:
        bool operator()(const string &s1,const string &s2){
	    return s1.size() < s2.size();
	}
};

void processor_vector(vector<string>&,ifstream&);
void display_vector(const vector<string>&,ofstream&);

int main(){
    ifstream ifile("exercise3.2.in");
    ofstream ofile("exercise3.2.out");

    if(!ifile || !ofile){
        cerr << "\nUnable to open file -- bailing out !\n";
	return -1;
    }

    vector<string> svec;
    processor_vector(svec,ifile);

    sort(svec.begin(),svec.end());
    stable_sort(svec.begin(),svec.end(),LessThan());

    display_vector(svec,ofile);
}

void processor_vector(vector<string> &svec,ifstream &ifile){
    string word;
    while(ifile >> word){
        svec.push_back(word);    
    }
}
/*
void display_vector(vector<string> &svec,ofstream &ofile){
    
    for(int ix = 0;ix < svec.size();ix++){
        ofile << "svec[ " << ix << " ]: "
	      << svec[ix] << endl;
    }
    ofile << endl;
}
*/
template<typename elemtype>
void display_vector(const vector<elemtype> &vec,ofstream &ofile){
    
    typename vector<elemtype>::const_iterator it = vec.begin();
    typename std::vector<elemtype>::const_iterator it_end = vec.end();

    int ix = 1;
    for(;it != it_end;it++){
        ofile << "vec[ " << (ix - 1) << " ]: "
	      << *it  << endl;
    }
   ofile << endl;
}
