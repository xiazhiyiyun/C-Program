#include <iterator>
#include <iostream>

using namespace std;

#ifndef _TRIANGULAR_ITERATOR
#define _TRIANGULAR_ITERATOR
class Triangular_iterator{
    public:
        Triangular_iterator( int index ): _index (index -1) {}

  	inline bool operator== ( Triangular_iterator& ) const;
	inline bool operator!= ( Triangular_iterator& ) const;
	inline int operator*() const ;
	inline Triangular_iterator& operator++();
	inline Triangular_iterator operator++( int );

    private:
        int _index;
	void check_integrity() const;
};

#endif
/*
#ifndef _TRIANGULAR_ITERATOR
#define _TRIANGULAR_ITERATOR
*/
