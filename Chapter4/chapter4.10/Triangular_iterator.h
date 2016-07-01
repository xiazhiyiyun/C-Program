#include <iterator>
#include <iostream>

using namespace std;

#ifndef _TRIANGULAR_ITERATOR
#define _TRIANGULAR_ITERATOR
class Triangular_iterator{
    public:
        Triangular_iterator( int index ): _index (index -1) {}

  	bool operator== ( Triangular_iterator& ) const;
	bool operator!= ( Triangular_iterator& ) const;
	int operator*() const ;
	Triangular_iterator& operator++();
	Triangular_iterator operator++( int );

    private:
        int _index;
	void check_integrity() const;
};
#endif
