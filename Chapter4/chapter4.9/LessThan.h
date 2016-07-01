using namespace std;

class LessThan
{
    public:
        LessThan(int val):_val(val) { }

	int cam_val() const {
	    return _val;
	}

	void cam_val(int val){
	    _val = val;
	}

	bool operator() (int) const; 
	/*
	{
	    return val < _val;
	}
	*/
    private:
        int _val;
};
/*
inline bool LessThan::operator()(int val) const{
    return val < _val;
}
*/
