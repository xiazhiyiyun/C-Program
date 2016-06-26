#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    int vec_size = 10;
    const int array_size = 5; // array can only receive the constant number as the size.
    int arr[ array_size ] = { 1, 2, 3, 4, 5};
    //vector<int> ivec(vec_size);
    vector<int> ivec;
    //copy(arr,arr + array_size,ivec.begin());
    copy(arr,arr + array_size,back_inserter(ivec));
    
    cout << "ivec.size() = " << ivec.size() << endl;
    cout << "ivec.max_size() = " << ivec.max_size() << endl;
}
