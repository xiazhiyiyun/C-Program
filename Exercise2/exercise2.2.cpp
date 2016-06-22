#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool pentag_seq(int size,vector<int> &vec);
void print_seq(const vector<int> &vec,const string &title,ostream &os = cout);

int main(){
    string title = "Pentagonal Numeric Series";
    vector<int> vec;
    if(pentag_seq(0,vec))
        print_seq(vec,title);
    if(pentag_seq(12,vec))
        print_seq(vec,title);
    if(pentag_seq(20,vec))
        print_seq(vec,title);
    if(pentag_seq(100,vec))
        print_seq(vec,title);
    if(pentag_seq(1000,vec))
        print_seq(vec,title);
}

bool pentag_seq(int size,vector<int> &vec){
    if(size <= 0 || size > 100){
        cerr << "pentag_seq():oops:invalid size: " 
	     << size << " can't fuifill request.\n";
	return false;
    }
    for(int ix = vec.size()+1;ix < size;ix++){
        int elem =  ix * (3 * ix - 1) / 2;
        vec.push_back(elem);
    }
    return true;
}

void print_seq(const vector<int> &vec,const string &title,ostream &os){
    os << title << endl << "\t";
    for(int ix = 0;ix < vec.size();ix++){
        os << vec[ix] << ( !((ix+1) % 10) ? "\n\t" :" "); 
    }
    os << endl;
} 

