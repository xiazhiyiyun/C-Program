using namespace std;

template < typename elemType, typename Comp >
class LessThanPred {
public:
    LessThanPred(const elemType &val): _val(val){
    }

    bool operator() ( const elemType &val ) const{
	Comp comp;
	return comp(val,_val);
    }
    void val (const elemType &val){
	_val = val;
    }
    elemType & val(){
	return _val;
    }
private:
    elemType _val;
};
