#include "Triangular_iterator.h"
#include "Triangular.h"
#include <cstdlib>

using namespace std;

inline bool Triangular_iterator::operator==( Triangular_iterator &Tri_it) const {
    return (_index == Tri_it._index);
}

inline bool Triangular_iterator::operator!=( Triangular_iterator &Tri_it) const {
    return (_index != Tri_it._index);
}

inline int Triangular_iterator::operator*() const {

    check_integrity(); 
    return (Triangular::_elems[_index]);
}

inline void Triangular_iterator::check_integrity() const {
    if( _index >= Triangular::_max_elems )
        exit(100);
//        throw iterator_overflow();

    if( _index >= Triangular::_elems.size() ){
        Triangular::gen_elements( _index + 1 );
    }
}

inline Triangular_iterator&  Triangular_iterator::operator++(){
    ++_index;
    check_integrity();
    return *this;
}

inline Triangular_iterator Triangular_iterator::operator++(int){
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}
