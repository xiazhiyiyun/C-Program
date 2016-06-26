#include <vector>
#include <iostream>

using namespace std;

class Triangular{
    public:
    	static bool is_elem( int value );
	static void gen_elements( int length );
	static void gen_element_to_value( int value);
	static void display( int length, int beg_bos, ostream &os = cout);
    private:
        static const int _max_elems = 1024;
	static vector<int> _elems;
};
