#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Type>
inline Type max(Type val_1,Type val_2){
    return val_1 > val_2 ? val_1 : val_2;
}

template <typename elemType>
inline elemType max(const vector<elemType> &val){
    return *max_element( val.begin(),val.end() );
}

template <typename arrayType>
inline arrayType max( const arrayType *parray,int size){
    return *max_element( parray,parray + size );
} 


int main(){
    string sarray[] = {"we","were","her","pride","of","ten"};
    vector<string> svec( sarray,sarray + 6);

    int iarray[] = {12,70,2,169,1,5,29};
    vector<int> ivec( sarray,sarray + 7);

    float farray[] = {2.5,24.8,18.7,4.1,23.9};
    vector<float> fvec( sarray,sarray + 5);

    int imax = max( max(ivec),max(iarray,7));
    float fmax = max( max(fvec),max(farray,5));
    string smax = max( max(svec),max(sarray,6));

    cout << "imax souble be 169 --found: "<< imax << '\n';
    cout << "fmax souble be 24.8 --found: "<< fmax << '\n';
    cout << "smax souble be were --found: "<< smax << '\n';

}
