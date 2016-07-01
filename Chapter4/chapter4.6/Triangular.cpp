#include <iostream>
#include <iterator>
#include <algorithm>
#include "Triangular.h"

vector<int> Triangular::_elems;

bool Triangular::is_elem(int value){
    if( !_elems.size() || ( value > _elems.back() ) )
        gen_element_to_value( value );
    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();
    found_it = find(_elems.begin(),end_it,value);
    return (found_it != end_it);
}
void Triangular::gen_elements( int length ){
    if(length > _max_elems){
        cerr << "Triangular: Oops: length too large! "
	     << length << " -- excedds max size of "
	     << _max_elems <<'\n'; 
    }
        
    if(length <= _elems.size())
        return;
    
    for(int ix = _elems.size() + 1; ix <= length; ix++){
//        cout << "elems to value: " << ix * (ix + 1) / 2 << endl;
	_elems.push_back( ix * (ix + 1) / 2);
    }
}
void Triangular::gen_element_to_value( int value){
    int ix = 0;
    if(!_elems.size()){
        _elems.push_back(1);
	ix = 1;
    }

    while(_elems.back() < value && ix < _max_elems){
//        cout << "elems to value: " << ix * (ix + 1) / 2 << endl;
	ix++;
	_elems.push_back( ix * (ix + 1) / 2);
    }
}
void Triangular::display( int length, int beg_bos, ostream &os ){
    if(length < 0 || beg_bos + length > _max_elems){
        cerr << "err:display();ircorrect parameter." << endl;
    }
    os << "The Triangular sequence: ";
    for(int ix = 0;ix < length;ix++){
        os << _elems[ beg_bos + ix ] << (ix + 1) % 10 ? " " : "\n";
    }
}


bool Triangular::next(int &val) const {

    if( _next < 0 || _next >= _elems.size() ){
	return false; 
    }
    else if( _next >= _beg_pos + _length - 1){
        return  false;
    }
    else{
	val = _elems[_next];
	_next++;
	return true;
    }
}
