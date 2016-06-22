#include <iostream>
#include <vector>
#include <cstdlib> // srand(seed);rand();exit(status)
using namespace std;

void display(vector<int> vec);
void swap(int &val1,int &val2);
void bubble_sort(vector<int> &vec);
void init(vector<int> &vec,int size);

int main(){
    int size = 20;
    vector<int> vec(size);
    init(vec,size); 
    cout << "vector before sort: " << endl;
    display(vec);
    bubble_sort(vec);
    cout << "vector after sort: " << endl;
    display(vec);
}

void init(vector<int> &vec,int size){
    for(int ix = 0;ix < size;ix++){
        srand(ix);
        vec[ix] = rand() % 100;
    }
}
void display(vector<int> vec){
    for(int ix = 0;ix < vec.size();ix++){
        cout << vec[ix] << ' ';
    }
    cout << endl;
}

void swap(int &val1,int &val2){
    int temp;
    temp = val1;
    val1 = val2;
    val2 = temp;
}
void bubble_sort(vector<int> &vec){
    for(int ix = 0;ix < vec.size();ix++){
        for(int jx = ix + 1;jx < vec.size();jx++){
	    if(vec[jx] < vec[ix]){
	        swap(vec[ix],vec[jx]);
	    }
	}
    }
}
