#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


inline int max(int val_1,int val_2){
    return val_1 > val_2 ? val_1 : val_2;
}

inline float max(float val_1,float val_2){
    return val_1 > val_2 ? val_1 : val_2;
}

inline string max(const string &val_1,const string &val_2){
    return val_1 > val_2 ? val_1 : val_2;
}

inline int max(const vector<int> &val){
    return *max_element( val.begin(),val.end() );
}

inline float max(const vector<float> &val){
    return *max_element( val.begin(),val.end() );
}

inline string max(const vector<string> &val){
    return *max_element( val.begin(),val.end() );
}

inline int max( const int *parray,int size){
    return *max_element( parray,parray + size );
} 

inline float max( const float *parray,int size){
    return *max_element( parray,parray + size );
}

inline string max( const string *parray,int size){
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
