#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<int> *pentag_seq(int size);
bool pentag_elem(int pos,int &elem);
void print_seq(const vector<int> &vec,const string &title = "Pentagonal Numeric Series",ostream &os = cout);

int main(){
    int elem;
    if(pentag_elem(0,elem)){
        cout << elem << endl;
    }
    if(pentag_elem(10,elem)){
        cout << elem << endl;
    }
    if(pentag_elem(20,elem)){
        cout << elem << endl;
    }
    if(pentag_elem(12,elem)){
        cout << elem << endl;
    }
}

const vector<int> *pentag_seq(int size){
    if(size <= 0 || size > 100){
        cerr << "pentag_seq():oops:invalid size: " 
	     << size << " can't fuifill request.\n";
	return 0;
    }
    static vector<int> seq;
    if(size > seq.size()){
	for(int ix = seq.size()+1;ix <= size;ix++){
	    int elem =  ix * (3 * ix - 1) / 2;
            seq.push_back(elem);
	}
    }
    return &seq;
}
bool pentag_elem(int pos,int &elem){
    const vector<int> *pseq = pentag_seq(pos);
    if(!pseq){
        elem = 0;
	return false;
    }
    elem = (*pseq)[pos -1];
    return true;
}

void print_seq(const vector<int> &vec,const string &title,ostream &os){
    os << title << endl << "\t";
    for(int ix = 0;ix < vec.size();ix++){
        os << vec[ix] << ( !((ix+1) % 10) ? "\n\t" :" "); 
    }
    os << endl;
} 

