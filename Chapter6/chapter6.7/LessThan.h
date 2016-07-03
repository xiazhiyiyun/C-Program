using namespace std;

template <typename elemType>
class LessThan {

public:
    LessThan( const elemType &val ):_val(val) {}

    bool operator() ( const elemType &val ) const {
	return val < _val;
    }

    void val(const elemType &val) {
	_val = val;
    }

    elemType & val(){
	return _val;
    }
private:
    elemType _val;
};
