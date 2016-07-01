#include <vector>
#include <iostream>

using namespace std;

class Triangular{
    public:

        Triangular(int len = 1,int beg = 1){
	    _length = len > 0 ? len : 1;
	    _beg_pos = beg > 0 ? beg : 1;
	    _next = _beg_pos -1;
	    gen_elements(_beg_pos + _length - 1);
	}

	int length() const {
	    return _length;
	}

	int beg_pos() const {
	    return _beg_pos;
	}
	
	bool next_reset()  const {
	    _next = _beg_pos - 1;
	}
	bool next(int &val) const;
    	static bool is_elem( int value );
	static void gen_elements( int length );
	static void gen_element_to_value( int value);
	static void display( int length, int beg_bos, ostream &os = cout);
    private:
        static const int _max_elems = 1024;
	static vector<int> _elems;
	int _length;
	int _beg_pos;
	mutable int _next;
};
